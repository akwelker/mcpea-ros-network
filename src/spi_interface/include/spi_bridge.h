/**
 *  @file spi_bridge.h
 *  @author Adam Welker
 *  @date Summer 2025
 * 
 *  @brief Header file for the SPI bridge. Class is able to read SPI in 126 byte
 *  segments. If publish is on, writes a time stamp and the 126 words into a text
 *  file located in spi_interface/logs. This should run as fast as possible. The 
 *  node publishes at a rate of 500 hz max 
 *       
 */

#ifndef SPI_BRIDGE_HPP
#define SPI_BRIDGE_HPP
#define TIMEOUT_MS 500

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <fstream>
#include <vector>
#include <mutex>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/u_int8_multi_array.hpp"

#include "wiringPi.h"
#include "wiringPiSPI.h"

// ================= SPI CONFIG =================
#define CHANNEL 0
#define SPI_SPEED 5000000
#define SPI_MODE 3

// SPI works in BYTES
constexpr std::size_t SPI_BUFFER_SIZE_BYTES = 126;
constexpr std::size_t SPI_BUFFER_SIZE_WORDS = 126;
// ==============================================

class Spi_Bridge : public rclcpp::Node
{
public:
    Spi_Bridge(double publish_rate);

    ~Spi_Bridge() override;

private:
    // Raw SPI byte buffer (in-place RW)
    std::vector<uint8_t> spi_buffer_;

    // Logical data (8bit words)
    std::vector<uint8_t> input_data_;
    std::vector<uint8_t> output_data_;

    std::mutex data_mutex_;

    std::chrono::time_point<std::chrono::steady_clock> last_command_time;

    double publish_rate_;

    rclcpp::Publisher<std_msgs::msg::UInt8MultiArray>::SharedPtr raw_data_publisher_;
    rclcpp::Subscription<std_msgs::msg::UInt8MultiArray>::SharedPtr raw_data_subscriber_;

    rclcpp::TimerBase::SharedPtr publish_timer_;
    rclcpp::TimerBase::SharedPtr spi_timer_;

    // Callbacks
    void raw_data_sub_callback(
        const std_msgs::msg::UInt8MultiArray::SharedPtr msg);

    void raw_data_pub_callback();
    void spi_transaction();

    // Helpers
    bool verify_checksum(const uint8_t* data);

    bool timeout_flag;
};

#endif // SPI_BRIDGE_HPP
