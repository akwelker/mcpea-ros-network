/**
 *  @file actuator_bridge_bridge.h
 *  @author Adam Welker
 *  @date Summer 2025
 * 
 *  @brief A new iteration of the SPI to ros bridge for an MC-PEA. This one will 
 *  constantly read in data from the actuator and instantly publish telemetry data.
 *  Telemetry data will be constantly published at 500 hz. Spi will be read at up
 *  to 500 hz, and commands will be assumed to be stationary (i.e., always keep the last command)
 *       
 */

#ifndef ACTUATOR_BRIDGE_HPP
#define ACTUATOR_BRIDGE_HPP

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <fstream>
#include <vector>
#include <mutex>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/u_int16_multi_array.hpp"
#include <spi_interface/msg/mcpea_telemetry.hpp>
#include <spi_interface/msg/mcpea_command.hpp>


#include "wiringPi.h"
#include "wiringPiSPI.h"

// ================= SPI CONFIG =================
#define CHANNEL 0
#define SPI_SPEED 500
#define SPI_MODE 0b11

#define SPI_BUFFER_SIZE 126
// ================= SPI TELEMETRY INDICES ====================


#define ACCEL1_INDEX 0
#define ACCEL2_INDEX 4
#define ACCEL3_INDEX 8
#define MOTOR_ABS_VEL_INDEX 12
#define MOTOR_ABS_POS_INDEX 16
#define BUS_VOLTAGE_INDEX 20
#define STAGE_TEMP_INDEX 24
#define MOTOR_INC_POS_INDEX 28
#define MOTOR_INC_VEL_INDEX 32
#define JOINT_POSITION_INDEX 36
#define JOINT_VELOCITY_INDEX 40
#define DES_CURRENT_INDEX 44
#define ACT_CURRENT_INDEX 48
#define DES_TORQUE_INDEX 52
#define ERROR_CODE_INDEX 56
#define CONTROL_EFFORT_INDEX 60

class Actuator_Bridge : public rclcpp::Node
{
public:
    Actuator_Bridge(double publish_rate);

    ~Actuator_Bridge() override;

private:
    // Raw SPI byte buffer (in-place RW)
    unsigned char *spi_buffer;

    // Logical data (words)
    unsigned char *input_data;
    unsigned char *output_data;

    std::mutex data_mutex;

    double publish_rate;

    rclcpp::Publisher<spi_interface::msg::McpeaTelemetry>::SharedPtr telemetry_publisher;
    rclcpp::Subscription<spi_interface::msg::McpeaCommand>::SharedPtr command_subscriber;

    rclcpp::TimerBase::SharedPtr publish_timer;
    rclcpp::TimerBase::SharedPtr spi_timer;

    // Callbacks
    /**
     * The ros node at this point in time does exactly three things
     * 1.) SPI transactions happen at 500 hz. input data is exchanged for output telemetry binary
     * 2.) Telemetry data is published to the ROS network at 25 Hz
     * 3.) As command data command data comes in, the input data is changed
     */
    void command_sub_callback(
        const spi_interface::msg::McpeaCommand::SharedPtr msg);

    void telemetry_pub_callback();
    void spi_transaction();

    // helper functions
    float convert_to_float(const uint8_t data1, const uint8_t data2, const uint8_t data3, const uint8_t data4);

    uint8_t get_checksum_1(const uint8_t* data);
    uint8_t get_checksum_2(const uint8_t* data);
    bool verify_checksum(const uint8_t* data);

    int get_on_off_code(int service_code);
};

#endif // ACTUATOR_BRIDGE
