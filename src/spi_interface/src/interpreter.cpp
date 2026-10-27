/**
 * @file interpreter.cpp
 * 
 * @brief This file contains the implementation of the Interpreter class.
 * 
 * @author Adam Welker
 * @date Summer 2025
 */

#include "interpreter.h"


Interpreter::Interpreter():Node("Interpreter")
{
    // Initialize the class variables
    this->message_composition_flag_ = false;

    // Create a publisher for the raw data
    this->raw_data_publisher_ = this->create_publisher<spi_interface::msg::McpeaTelemetry>("actuator_data_out", 0);

    // Create subscriber for the raw data
    this->raw_data_subscriber_ = this->create_subscription<std_msgs::msg::UInt8MultiArray>(
        "actuator_data_in", 0,
        std::bind(&Interpreter::raw_data_sub_callback, this, std::placeholders::_1));


    // Create command publishers and subscribers

    this->command_publisher_ = this->create_publisher<std_msgs::msg::UInt8MultiArray>("actuator_command_out", 0);

    
    this->command_subscriber_ = this->create_subscription<spi_interface::msg::McpeaCommand>(
        "actuator_command_in", 0,
        std::bind(&Interpreter::command_sub_callback, this, std::placeholders::_1));


    // ros service subscribers
    this->motor_enable_service = this->create_service<std_srvs::srv::Trigger>("enable_motor", std::bind(&Interpreter::enable_service_call, this, std::placeholders::_1, std::placeholders::_2));
    this->motor_reset_service = this->create_service<std_srvs::srv::Trigger>("reset_motor", std::bind(&Interpreter::reset_service_call, this, std::placeholders::_1, std::placeholders::_2));
    this->motor_disable_service = this->create_service<std_srvs::srv::Trigger>("disable_motor", std::bind(&Interpreter::disable_service_call, this, std::placeholders::_1, std::placeholders::_2));



    // set boolean buffer value
    this->motor_enable_flag = false;
    this->motor_disable_flag = false;
    this->motor_reset_flag = false;
    this->joint_angle_zero_flag = false;
    this->boom_angle_zero_flag = false;


    
    RCLCPP_INFO(this->get_logger(), "Interpreter Running");

}

/**
 * This function is called each time that the data is received from the 
 * actuator via the SPI bus and put into the ros network.
 * 
 * @param: msg: the ros message of the raw SPI data submitted
 */
void Interpreter::raw_data_sub_callback(const std_msgs::msg::UInt8MultiArray spi_msg)
{
    raw_data_pub_callback(spi_msg);
};


/**
 * If check sums for incoming data have been verified, this fuction is called
 * to publish the telemetry data from the robot
 */
void Interpreter::raw_data_pub_callback(const std_msgs::msg::UInt8MultiArray spi_msg)
{
   spi_interface::msg::McpeaTelemetry outmsg;

    float accel1 = convert_to_float(spi_msg.data[ACCEL1_INDEX], 
                                    spi_msg.data[ACCEL1_INDEX+1], 
                                    spi_msg.data[ACCEL1_INDEX+2], 
                                    spi_msg.data[ACCEL1_INDEX+3]);
    outmsg.set__accel_1(accel1);
    
    
    float accel2 = convert_to_float(spi_msg.data[ACCEL2_INDEX], 
                                    spi_msg.data[ACCEL2_INDEX+1], 
                                    spi_msg.data[ACCEL2_INDEX+2], 
                                    spi_msg.data[ACCEL2_INDEX+3]);
    outmsg.set__accel_2(accel2);

    
    
    float accel3 = convert_to_float(spi_msg.data[ACCEL3_INDEX], 
                                    spi_msg.data[ACCEL3_INDEX+1], 
                                    spi_msg.data[ACCEL3_INDEX+2], 
                                    spi_msg.data[ACCEL3_INDEX+3]);
    outmsg.set__accel_3(accel3);
    
    
    float motor_abs_velocity = convert_to_float(spi_msg.data[MOTOR_ABS_VEL_INDEX], 
                                                spi_msg.data[MOTOR_ABS_VEL_INDEX+1], 
                                                spi_msg.data[MOTOR_ABS_VEL_INDEX+2], 
                                                spi_msg.data[MOTOR_ABS_VEL_INDEX+3]);
    outmsg.set__motor_abs_velocity(motor_abs_velocity);
    
    
    float motor_abs_position = convert_to_float(spi_msg.data[MOTOR_ABS_POS_INDEX], 
                                                spi_msg.data[MOTOR_ABS_POS_INDEX+1], 
                                                spi_msg.data[MOTOR_ABS_POS_INDEX+2], 
                                                spi_msg.data[MOTOR_ABS_POS_INDEX+3]);
    outmsg.set__motor_abs_position(motor_abs_position);
    
    
    float ing_bus_voltage = convert_to_float(spi_msg.data[BUS_VOLTAGE_INDEX], 
                                             spi_msg.data[BUS_VOLTAGE_INDEX+1], 
                                             spi_msg.data[BUS_VOLTAGE_INDEX+2], 
                                             spi_msg.data[BUS_VOLTAGE_INDEX+3]);
    outmsg.set__ing_bus_voltage(ing_bus_voltage);
    

    float power_stage_temp = convert_to_float(spi_msg.data[STAGE_TEMP_INDEX], 
                                                  spi_msg.data[STAGE_TEMP_INDEX+1], 
                                                  spi_msg.data[STAGE_TEMP_INDEX+2], 
                                                  spi_msg.data[STAGE_TEMP_INDEX+3]);
    outmsg.set__power_stage_temp(power_stage_temp);

    
    float motor_inc_position = convert_to_float(spi_msg.data[MOTOR_INC_POS_INDEX], 
                                                spi_msg.data[MOTOR_INC_POS_INDEX+1], 
                                                spi_msg.data[MOTOR_INC_POS_INDEX+2], 
                                                spi_msg.data[MOTOR_INC_POS_INDEX+3]);
    outmsg.set__motor_inc_position(motor_inc_position);
    

    float motor_inc_velocity = convert_to_float(spi_msg.data[MOTOR_INC_VEL_INDEX], 
                                                spi_msg.data[MOTOR_INC_VEL_INDEX+1], 
                                                spi_msg.data[MOTOR_INC_VEL_INDEX+2], 
                                                spi_msg.data[MOTOR_INC_VEL_INDEX+3]);
    outmsg.set__motor_inc_velocity(motor_inc_velocity);

    

    float des_current = convert_to_float(spi_msg.data[DES_CURRENT_INDEX], 
                                         spi_msg.data[DES_CURRENT_INDEX+1], 
                                         spi_msg.data[DES_CURRENT_INDEX+2], 
                                         spi_msg.data[DES_CURRENT_INDEX+3]);
    outmsg.set__des_current(des_current);
    

    float act_current = convert_to_float(spi_msg.data[ACT_CURRENT_INDEX], 
                                             spi_msg.data[ACT_CURRENT_INDEX+1], 
                                             spi_msg.data[ACT_CURRENT_INDEX+2], 
                                             spi_msg.data[ACT_CURRENT_INDEX+3]);
    outmsg.set__act_current(act_current);
    
    float des_torque = convert_to_float(spi_msg.data[DES_TORQUE_INDEX], 
                                             spi_msg.data[DES_TORQUE_INDEX+1], 
                                             spi_msg.data[DES_TORQUE_INDEX+2], 
                                             spi_msg.data[DES_TORQUE_INDEX+3]);
    outmsg.set__des_torque(des_torque);
    

    float error_code = convert_to_float(spi_msg.data[ERROR_CODE_INDEX], 
                                             spi_msg.data[ERROR_CODE_INDEX+1], 
                                             spi_msg.data[ERROR_CODE_INDEX+2], 
                                             spi_msg.data[ERROR_CODE_INDEX+3]);
    outmsg.set__error_code(error_code);

    float control_effort = convert_to_float(spi_msg.data[CONTROL_EFFORT_INDEX], 
                                                spi_msg.data[CONTROL_EFFORT_INDEX+1], 
                                                spi_msg.data[CONTROL_EFFORT_INDEX+2], 
                                                spi_msg.data[CONTROL_EFFORT_INDEX+3]);
    outmsg.set__control_effort(control_effort);


    float joint_position = convert_to_float(spi_msg.data[JOINT_POSITION_INDEX], 
                                                spi_msg.data[JOINT_POSITION_INDEX+1], 
                                                spi_msg.data[JOINT_POSITION_INDEX+2], 
                                                spi_msg.data[JOINT_POSITION_INDEX+3]);
    outmsg.set__joint_position(joint_position);

    float joint_velocity = convert_to_float(spi_msg.data[JOINT_VELOCITY_INDEX], 
                                                spi_msg.data[JOINT_VELOCITY_INDEX+1], 
                                                spi_msg.data[JOINT_VELOCITY_INDEX+2], 
                                                spi_msg.data[JOINT_VELOCITY_INDEX+3]);
    outmsg.set__joint_velocity(joint_velocity);

    float boom_angle = convert_to_float(spi_msg.data[BOOM_ANGLE_INDEX], 
                                                spi_msg.data[BOOM_ANGLE_INDEX+1], 
                                                spi_msg.data[BOOM_ANGLE_INDEX+2], 
                                                spi_msg.data[BOOM_ANGLE_INDEX+3]);
    outmsg.set__boom_angle(boom_angle);

    this->raw_data_publisher_->publish(outmsg);

};


void Interpreter::command_sub_callback(const spi_interface::msg::McpeaCommand msg)
{
    // first extract relavent data from the command message

    float torque_limit = msg.torque_limit;
    float motor_state_cmd = msg.motor_state_cmd;
    float ff_torque = msg.feedforward_torque;
    float current_limit = msg.current_limit;
    float control_mode = msg.control_mode;
    float data_1 = msg.data_1; // usually the reference signal
    float data_2 = msg.data_2; // usually virutal stiffness
    float data_3 = msg.data_3; // usually virtual damping
    float data_4 = msg.data_4; // usually virtual damping
    float data_5 = msg.data_5; // usually virtual damping
    float dynamic_comp_gain = msg.dynamic_comp_gain;

    std::vector<uint8_t> data_out(BUFFER_SIZE); // declare data out

    // now fill the data out with the integer forms of the float data

    std::array<uint8_t,4> data_out_torque_limit_vec = this->convert_to_integers(torque_limit);
    data_out[TORQUE_LIM_INDEX] = data_out_torque_limit_vec[0];
    data_out[TORQUE_LIM_INDEX+1] = data_out_torque_limit_vec[1];
    data_out[TORQUE_LIM_INDEX+2] = data_out_torque_limit_vec[2];
    data_out[TORQUE_LIM_INDEX+3] = data_out_torque_limit_vec[3];

    std::array<uint8_t,4> data_out_motor_state_vec = this->convert_to_integers(motor_state_cmd);
    data_out[ENABLE_INDEX] = data_out_motor_state_vec[0];
    data_out[ENABLE_INDEX+1] = data_out_motor_state_vec[1];
    data_out[ENABLE_INDEX+2] = data_out_motor_state_vec[2];
    data_out[ENABLE_INDEX+3] = data_out_motor_state_vec[3];

    std::array<uint8_t,4> data_out_current_limit_vec = this->convert_to_integers(current_limit);
    data_out[CURR_LIM_INDEX] = data_out_current_limit_vec[0];
    data_out[CURR_LIM_INDEX+1] = data_out_current_limit_vec[1];
    data_out[CURR_LIM_INDEX+2] = data_out_current_limit_vec[2];
    data_out[CURR_LIM_INDEX+3] = data_out_current_limit_vec[3];

    std::array<uint8_t,4> data_out_ff_torque_vec = this->convert_to_integers(ff_torque);
    data_out[FF_TORQUE_INDEX] = data_out_ff_torque_vec[0];
    data_out[FF_TORQUE_INDEX+1] = data_out_ff_torque_vec[1];
    data_out[FF_TORQUE_INDEX+2] = data_out_ff_torque_vec[2];
    data_out[FF_TORQUE_INDEX+3] = data_out_ff_torque_vec[3];

    std::array<uint8_t,4> data_out_control_mode_vec = this->convert_to_integers(control_mode);
    data_out[CONTROL_MODE_INDEX] = data_out_control_mode_vec[0];
    data_out[CONTROL_MODE_INDEX+1] = data_out_control_mode_vec[1];
    data_out[CONTROL_MODE_INDEX+2] = data_out_control_mode_vec[2];
    data_out[CONTROL_MODE_INDEX+3] = data_out_control_mode_vec[3];

    std::array<uint8_t,4> data_out_data_1_vec = this->convert_to_integers(data_1);
    data_out[DATA_1_INDEX] = data_out_data_1_vec[0];
    data_out[DATA_1_INDEX+1] = data_out_data_1_vec[1];
    data_out[DATA_1_INDEX+2] = data_out_data_1_vec[2];
    data_out[DATA_1_INDEX+3] = data_out_data_1_vec[3];

    std::array<uint8_t,4> data_out_data_2_vec = this->convert_to_integers(data_2);
    data_out[DATA_2_INDEX] = data_out_data_2_vec[0];
    data_out[DATA_2_INDEX+1] = data_out_data_2_vec[1];
    data_out[DATA_2_INDEX+2] = data_out_data_2_vec[2];
    data_out[DATA_2_INDEX+3] = data_out_data_2_vec[3];

    std::array<uint8_t,4> data_out_data_3_vec = this->convert_to_integers(data_3);
    data_out[DATA_3_INDEX] = data_out_data_3_vec[0];
    data_out[DATA_3_INDEX+1] = data_out_data_3_vec[1];
    data_out[DATA_3_INDEX+2] = data_out_data_3_vec[2];
    data_out[DATA_3_INDEX+3] = data_out_data_3_vec[3];

    std::array<uint8_t,4> data_out_data_4_vec = this->convert_to_integers(data_4);
    data_out[DATA_4_INDEX] = data_out_data_4_vec[0];
    data_out[DATA_4_INDEX+1] = data_out_data_4_vec[1];
    data_out[DATA_4_INDEX+2] = data_out_data_4_vec[2];
    data_out[DATA_4_INDEX+3] = data_out_data_4_vec[3];
    
    std::array<uint8_t,4> data_out_data_5_vec = this->convert_to_integers(data_5);
    data_out[DATA_5_INDEX] = data_out_data_5_vec[0];
    data_out[DATA_5_INDEX+1] = data_out_data_5_vec[1];
    data_out[DATA_5_INDEX+2] = data_out_data_5_vec[2];
    data_out[DATA_5_INDEX+3] = data_out_data_5_vec[3];

    std::array<uint8_t,4> data_out_dynamic_comp_gain_vec = this->convert_to_integers(dynamic_comp_gain);
    data_out[DYNAMIC_COMP_INDEX] = data_out_dynamic_comp_gain_vec[0];
    data_out[DYNAMIC_COMP_INDEX+1] = data_out_dynamic_comp_gain_vec[1];
    data_out[DYNAMIC_COMP_INDEX+2] = data_out_dynamic_comp_gain_vec[2];
    data_out[DYNAMIC_COMP_INDEX+3] = data_out_dynamic_comp_gain_vec[3];


    // if dynamic comp is on, then add that to the boolean input
    if(msg.dynamic_comp_on)
    {
        data_out[BOOL_BUFFER_INDEX] += (1 << (7-COMPENSATOR_ON_INDEX));
    }

    this->command_pub_callback(data_out);


    return;
};

void Interpreter::command_pub_callback(const std::vector<uint8_t> data_out)
{
    std_msgs::msg::UInt8MultiArray msg_out;



    // incorperation of checksum and boolean buffer
    std::vector<uint8_t> check_out = data_out;


    //Overwrite motor enable state if a service flag is up. Do in safest order
    if(this->motor_enable_flag)
    {
        float motor_code = 3;

        std::array<uint8_t,4> motor_code_arr = this->convert_to_integers(motor_code);
        
        check_out[ENABLE_INDEX] = motor_code_arr[0];
        check_out[ENABLE_INDEX+1] = motor_code_arr[1];
        check_out[ENABLE_INDEX+2] = motor_code_arr[2];
        check_out[ENABLE_INDEX+3] = motor_code_arr[3];
    }
    else if (this->motor_reset_flag)
    {
        float motor_code = 1;

        std::array<uint8_t,4> motor_code_arr = this->convert_to_integers(motor_code);
        
        check_out[ENABLE_INDEX] = motor_code_arr[0];
        check_out[ENABLE_INDEX+1] = motor_code_arr[1];
        check_out[ENABLE_INDEX+2] = motor_code_arr[2];
        check_out[ENABLE_INDEX+3] = motor_code_arr[3];
    }
    
    if (this->motor_reset_flag)
    {
        float motor_code = 4;

        std::array<uint8_t,4> motor_code_arr = this->convert_to_integers(motor_code);
        
        check_out[ENABLE_INDEX] = motor_code_arr[0];
        check_out[ENABLE_INDEX+1] = motor_code_arr[1];
        check_out[ENABLE_INDEX+2] = motor_code_arr[2];
        check_out[ENABLE_INDEX+3] = motor_code_arr[3];
    }
    


    //zeroing terms and dynamic comp.
    uint8_t boolean_float_values_addtn = 0;

    if (this->joint_angle_zero_flag)
    {
        boolean_float_values_addtn += (1 << (7-ZERO_JOINT_INDEX));
    }
    
    if (this->boom_angle_zero_flag)
    {
        boolean_float_values_addtn += (1 << (7-ZERO_BOOM_ANGLE_INDEX));
    }

    check_out[BOOL_BUFFER_INDEX] += boolean_float_values_addtn;


    //Add check sums
    check_out[124] = this->get_checksum_1(data_out.data());
    check_out[125] = this->get_checksum_2(data_out.data());

    msg_out.data = check_out;



    this->command_publisher_->publish(msg_out);
};

/**
 * As per the original labview code, finds the check sum 1
 * that will be delivered as part of the SPI code the PIC32
 * 
 * @param data: the raw data input. a 124 length array of unsigned 16 bit integers.
 * 
 * @return the first check sum value 
 */
uint8_t Interpreter::get_checksum_1(const uint8_t* data)
{
    uint8_t c0;

    uint8_t sum1;
    uint8_t sum2;
    
    int count = 124;

    for(int i = 0; i < count; i++)
    {
        sum1 = (sum1 + data[i]) % 255;
        sum2 = (sum1 + sum2) % 255;
    }

    c0 = 0xff - ((sum1 + sum2) % 0xff);

    return c0;
};


/**
 * As per the original labview code, finds the check sum 2
 * that will be delivered as part of the SPI code the PIC32
 * 
 * @param data: the raw data input. a 124 length array of unsigned 16 bit integers
 * 
 * @return the second check sum value 
 */
uint8_t Interpreter::get_checksum_2(const uint8_t* data)
{
    uint8_t c0;
    uint8_t c1;

    uint8_t sum1;
    uint8_t sum2;
    
    int count = 124;
    

    for(int i = 0; i < count; i++)
    {
        sum1 = (sum1 + data[i]) % 255;
        sum2 = (sum1 + sum2) % 255;
    }

    c0 = 0xff - ((sum1 + sum2) % 0xff);
    c1 = 0xff - ((sum1 + c0) % 0xff);

    return c1;   
};

/**
 *  Check sums come out from the PIC32 as well. This function verifies
 *  the checksums to make sure the data we're receiving is valid
 */
bool Interpreter::verify_checksum(const uint8_t* data)
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

/**
 * The interpreter class subscribes to a ros-service which 
 * asks the node to enable or disable the motor 
 * 
 * @param service_code: int describing the request. 1 for enable, -1 for disable,
 * and 2 for reset
 * 
 * @return the code to be sent to the PIC32. 3 for enable, 4 for disable, 1 for reset
 * 
 */
int Interpreter::get_on_off_code(int service_code)
{
    int return_code = 0;
    switch (service_code)
    {
        case 1: // enable motor
            return_code = 3;
            break;

        case -1: // disable motor
            return_code = 4;
            break;

        case 2: //reset
            return_code = 1;
            break;
        
        default:
            
            break;
    }

    return return_code;
};

/**
 * This function converts 4 8bit integers found in the SPI buffer into a single 
 * float value
 * 
 * @param data1: the first integer value. Corresponds with most significant bits
 * @param data2: the second integer
 * @param data3: the third int
 * @param data4: the 4th integer. Corresponds with LSB
 * 
 * @return data_float: the float that combines all 4 ints
 * 
 */
float Interpreter::convert_to_float(uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3)
{
{
    uint32_t bits = (static_cast<uint32_t>(b0) << 24) |
                    (static_cast<uint32_t>(b1) << 16) |
                    (static_cast<uint32_t>(b2) << 8)  |
                     static_cast<uint32_t>(b3);
    float value;
    std::memcpy(&value, &bits, sizeof(value));
    return value;
}
}

// /**
//  * This function converts a floating point value into a dynamic array of 4 
//  * 8-bit integers. Assume big endian
//  * 
//  * @param value: the data to be converted

// claud helped with this one
//  */
std::array<uint8_t, 4> Interpreter::convert_to_integers(float value)
{
    uint32_t bits;
    std::memcpy(&bits, &value, sizeof(bits));
    return { static_cast<uint8_t>(bits >> 24),
             static_cast<uint8_t>(bits >> 16),
             static_cast<uint8_t>(bits >> 8),
             static_cast<uint8_t>(bits) };
}


void Interpreter::enable_service_call(const std::shared_ptr<std_srvs::srv::Trigger::Request> request, std::shared_ptr<std_srvs::srv::Trigger::Response> response)
{
    this->motor_enable_flag = true;
    RCLCPP_WARN(rclcpp::get_logger("rclcpp"), "Motor Enabled!");
    response->success = true;
    response->message = "Motor Enabled!";
    return;
}


void Interpreter::reset_service_call(const std::shared_ptr<std_srvs::srv::Trigger::Request> request, std::shared_ptr<std_srvs::srv::Trigger::Response> response)
{
    this->motor_reset_flag = true;
    RCLCPP_WARN(rclcpp::get_logger("rclcpp"), "Motor Driver Reset!");
    response->success = true;
    response->message = "Motor Driver Reset!";
    return;
}


void Interpreter::disable_service_call(const std::shared_ptr<std_srvs::srv::Trigger::Request> request, std::shared_ptr<std_srvs::srv::Trigger::Response> response)
{
    this->motor_disable_flag = true;
    RCLCPP_WARN(rclcpp::get_logger("rclcpp"), "Motor Disabled!");
    response->success = true;
        response->message = "Motor Disabled!";
    return;
}