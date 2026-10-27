/**
 * @file interpreter.h
 * @brief This file contains the definition of the Interpreter class. It
 * is specific to the code put on  the PIC32 microcontroller. The interpreter
 * takes the raw SPI as 126 16-bit integers and interprets them into
 * meaningful data. The data is then published to the ROS2 topic
 * 
 * @author Adam Welker
 * @date Summer 2025
 *
 */

#ifndef INTERPERETER_H
#define INTERPERETER_H


// data in constants
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
#define BOOM_ANGLE_INDEX 64
#define CONTROL_EFFORT_INDEX 60


//data out placement constants
#define TORQUE_LIM_INDEX 0
#define ENABLE_INDEX 4
#define CURR_LIM_INDEX 8
#define FF_TORQUE_INDEX 12
#define CONTROL_MODE_INDEX 16
#define DATA_1_INDEX 20
#define DATA_2_INDEX 24
#define DATA_3_INDEX 28
#define DATA_4_INDEX 32
#define DATA_5_INDEX 36
#define DYNAMIC_COMP_INDEX 40

//Bool Buffer_Data
#define BOOL_BUFFER_INDEX 120
#define ZERO_JOINT_INDEX 1
#define COMPENSATOR_ON_INDEX 2
#define ZERO_BOOM_ANGLE_INDEX 3

#define BUFFER_SIZE 126


#include <chrono>
#include <functional>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>
#include <array>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_srvs/srv/trigger.hpp"
#include "std_msgs/msg/u_int16_multi_array.hpp"
#include <spi_interface/msg/mcpea_telemetry.hpp>
#include <spi_interface/msg/mcpea_command.hpp>
#include "std_msgs/msg/u_int8_multi_array.hpp"


class Interpreter: public rclcpp::Node
{
    public:

        /**
         * @brief Class Constructor.
         * 
         */
        Interpreter();
       

    private:

        // pubs and subs
        rclcpp::Subscription<std_msgs::msg::UInt8MultiArray>::SharedPtr raw_data_subscriber_;
        rclcpp::Publisher<spi_interface::msg::McpeaTelemetry>::SharedPtr raw_data_publisher_;

        rclcpp::Subscription<spi_interface::msg::McpeaCommand>::SharedPtr command_subscriber_;
        rclcpp::Publisher<std_msgs::msg::UInt8MultiArray>::SharedPtr command_publisher_;


        // services
        rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr motor_enable_service;
        rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr motor_reset_service;
        rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr motor_disable_service;

        // 


        // rclcpp::TimerBase::SharedPtr raw_data_timer_;
        // rclcpp::TimerBase::SharedPtr command_timer_;

        bool message_composition_flag_; // flag to indicate we're composing
        std::vector<uint8_t> actuator_request_out_;

        void raw_data_sub_callback(const std_msgs::msg::UInt8MultiArray spi_msg);
        void raw_data_pub_callback(const std_msgs::msg::UInt8MultiArray spi_msg);
        
        
        void command_sub_callback(const spi_interface::msg::McpeaCommand msg);
        void command_pub_callback(const std::vector<uint8_t> data_out);

        void enable_service_call(const std::shared_ptr<std_srvs::srv::Trigger::Request> request, std::shared_ptr<std_srvs::srv::Trigger::Response> response);
        void reset_service_call(const std::shared_ptr<std_srvs::srv::Trigger::Request> request, std::shared_ptr<std_srvs::srv::Trigger::Response> response);
        void disable_service_call(const std::shared_ptr<std_srvs::srv::Trigger::Request> request, std::shared_ptr<std_srvs::srv::Trigger::Response> response);

        float convert_to_float(const uint8_t data1, const uint8_t data2, const uint8_t data3, const uint8_t data4);

        std::array<uint8_t, 4>convert_to_integers(float value);

        uint8_t get_checksum_1(const uint8_t* data);
        uint8_t get_checksum_2(const uint8_t* data);
        bool verify_checksum(const uint8_t* data);

        int get_on_off_code(int service_code);


        // Values that encapsulate boolean command states that need to be 
        // transmitted (enable and disable motor)
        bool motor_enable_flag;
        bool motor_disable_flag;
        bool motor_reset_flag;
        bool joint_angle_zero_flag;
        bool boom_angle_zero_flag;

};
#endif