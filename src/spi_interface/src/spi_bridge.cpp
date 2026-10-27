/**
 * @file spi_bridge.cpp
 * @brief Implementation of the SPI bridge class. This class is responsible for
 * reading SPI data in 126 byte segments. If recording is enabled, it writes a
 * timestamp and the 126 words into a text file located in spi_interface/logs.
 * This class is designed to run as fast as possible, with a maximum publish rate
 * of 500 Hz.
 * 
 * @author Adam Welker
 * @date Summer 2025
 */

#include "spi_bridge.h"

Spi_Bridge::Spi_Bridge(double publish_rate)
: Node("SPI_Bridge"),
  publish_rate_(publish_rate)
{
    // Allocate buffers
    spi_buffer_.resize(SPI_BUFFER_SIZE_BYTES, 0);
    input_data_.resize(SPI_BUFFER_SIZE_WORDS, 0);
    output_data_.resize(SPI_BUFFER_SIZE_WORDS, 0);

    // ROS QoS
    auto qos = rclcpp::QoS(rclcpp::KeepLast(2));

    raw_data_publisher_ =
        this->create_publisher<std_msgs::msg::UInt8MultiArray>(
            "actuator_raw_data_in", qos);

    raw_data_subscriber_ =
        this->create_subscription<std_msgs::msg::UInt8MultiArray>(
            "actuator_raw_data_out",
            qos,
            std::bind(&Spi_Bridge::raw_data_sub_callback,
                      this,
                      std::placeholders::_1));

    publish_timer_ = this->create_wall_timer(
        std::chrono::duration<double>(1.0 / publish_rate_),
        std::bind(&Spi_Bridge::raw_data_pub_callback, this));


    spi_timer_ = this->create_wall_timer(
        std::chrono::milliseconds(1),
        std::bind(&Spi_Bridge::spi_transaction, this));

    // SPI init
    int fd = wiringPiSPISetupMode(CHANNEL, SPI_SPEED, SPI_MODE);
    if (fd < 0)
    {
        RCLCPP_FATAL(get_logger(), "SPI setup failed");
        throw std::runtime_error("SPI setup failed");
    }

    RCLCPP_INFO(get_logger(), "SPI bridge initialized");

    // record the current time
    this->last_command_time = std::chrono::steady_clock::now();

    this->timeout_flag = false;
}

Spi_Bridge::~Spi_Bridge()
{

}

// ================= SUB CALLBACK =================
void Spi_Bridge::raw_data_sub_callback(
    const std_msgs::msg::UInt8MultiArray::SharedPtr msg)
{
    std::lock_guard<std::mutex> lock(data_mutex_);

    std::memcpy(input_data_.data(), msg->data.data(), SPI_BUFFER_SIZE_BYTES);

    this->last_command_time = std::chrono::steady_clock::now();

    this->timeout_flag = false;
}

// ================= PUB CALLBACK =================
void Spi_Bridge::raw_data_pub_callback()
{
    std_msgs::msg::UInt8MultiArray msg;


    std::lock_guard<std::mutex> lock(data_mutex_);
    msg.data = output_data_;

    raw_data_publisher_->publish(msg);
}


// ================= SPI TRANSACTION =================
void Spi_Bridge::spi_transaction()
{
    std::lock_guard<std::mutex> lock(data_mutex_);

    std::chrono::time_point<std::chrono::steady_clock> curr_time = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(curr_time - this->last_command_time);

    if(duration.count() > TIMEOUT_MS && !this->timeout_flag)
    {
        std::memcpy(spi_buffer_.data(),
                    input_data_.data(),
                    SPI_BUFFER_SIZE_BYTES);
    }
    else if(!this->timeout_flag)
    {
        std::fill(spi_buffer_.begin(), spi_buffer_.end(), 0);
        RCLCPP_WARN(get_logger(), "Command Timeout!");
        this->timeout_flag = true;
    }

    // // Pack words into bytes
    // std::memcpy(spi_buffer_.data(),
    //             input_data_.data(),
    //             SPI_BUFFER_SIZE_BYTES);

    int result = wiringPiSPIDataRW(
        CHANNEL,
        spi_buffer_.data(),
        SPI_BUFFER_SIZE_BYTES);

    if (result < 0)
    {
        RCLCPP_ERROR(get_logger(), "SPI transaction failed");
        return;
    }

    if (Spi_Bridge::verify_checksum(spi_buffer_.data()))
    {
         // Unpack bytes into words
        std::memcpy(output_data_.data(),
                    spi_buffer_.data(),
                    SPI_BUFFER_SIZE_BYTES);
    }

    // Unpack bytes into words
    // std::memcpy(output_data_.data(),
    //                 spi_buffer_.data(),
    //                 SPI_BUFFER_SIZE_BYTES);


}

// ================= HELPERS =================


/**
 *  Check sums come out from the PIC32 as well. This function verifies
 *  the checksums to make sure the data we're receiving is valid
 */
bool Spi_Bridge::verify_checksum(const uint8_t* data)
{
    bool zero_check  = false;
    uint8_t sum1;
    uint8_t sum2;
    int count = 126;



    for(int i = 0; i < count; i++)
    {
        sum1 = (sum1 + data[i])%255;
        sum2 = (sum1 + sum2)%255;
    }

    if (data[count - 1] !=0 || data[count -2] != 0)
    {
        zero_check = true;
    }

    // RCLCPP_INFO(this->get_logger(), "Here");
    return ((sum1 == 0) && (sum2 == 0) && zero_check);
};
