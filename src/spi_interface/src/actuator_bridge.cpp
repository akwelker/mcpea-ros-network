/**
 * @file actuator_bridge.cpp
 * @brief Implementation of theactuator bridge class. This class is responsible for
 * reading SPI data in 126 byte segments.
 * This class is designed to run as fast as possible, with a maximum SPI rate
 * of 500 Hz.
 * 
 * @author Adam Welker
 * @date Summer 2025
 */

#include "actuator_bridge.h"

Actuator_Bridge::Actuator_Bridge(double publish_rate): Node("Actuator_Bridge")
{
    // ROS QoS
    auto qos = rclcpp::QoS(rclcpp::KeepLast(2));

    telemetry_publisher =
        this->create_publisher<spi_interface::msg::McpeaTelemetry>(
            "actuator_telemetry", qos);

    command_subscriber =
        this->create_subscription<spi_interface::msg::McpeaCommand>(
            "actuator_command",
            qos,
            std::bind(&Actuator_Bridge::command_sub_callback,
                      this,std::placeholders::_1));

    // publish_timer = this->create_wall_timer(
    //     std::chrono::duration<double>(1.0 / publish_rate),
    //     std::bind(&Actuator_Bridge::telemetry_pub_callback, this));

    spi_timer = this->create_wall_timer(
        std::chrono::duration<double>(1.0 / SPI_SPEED),
        std::bind(&Actuator_Bridge::spi_transaction, this));

    // SPI init
    int fd = wiringPiSPISetupMode(CHANNEL, SPI_SPEED, SPI_MODE);
    if (fd < 0)
    {
        RCLCPP_FATAL(get_logger(), "SPI setup failed");
        throw std::runtime_error("SPI setup failed");
    }

    RCLCPP_INFO(get_logger(), "SPI initialized");

    spi_buffer = new unsigned char[SPI_BUFFER_SIZE];
    input_data = new unsigned char[SPI_BUFFER_SIZE];
    output_data = new unsigned char[SPI_BUFFER_SIZE];
    // initialize all buffers to get rid of junk data
    for (int i = 0; i < SPI_BUFFER_SIZE; ++i)
    {
        spi_buffer[i] = 0x00;
        input_data[i] = 0xff;
        output_data[i] = 0x00;
    }
    RCLCPP_INFO(get_logger(), "Actuator Bridge initialized");
}

Actuator_Bridge::~Actuator_Bridge()
{
    delete[] spi_buffer;
    delete[] input_data;
    delete[] output_data; 
};

// ================= SUB CALLBACK =================
void Actuator_Bridge::command_sub_callback(
    const spi_interface::msg::McpeaCommand::SharedPtr msg)
{
    std::lock_guard<std::mutex> lock(data_mutex);

    for (int i = 0; i < SPI_BUFFER_SIZE; ++i)
        this->input_data[i] = 0xff;
}

// ================= PUB CALLBACK =================
void Actuator_Bridge::telemetry_pub_callback()
{
    spi_interface::msg::McpeaTelemetry outmsg;

    // std::lock_guard<std::mutex> lock(data_mutex);
    

    float accel1 = convert_to_float(this->output_data[ACCEL1_INDEX], 
                                    this->output_data[ACCEL1_INDEX+1], 
                                    this->output_data[ACCEL1_INDEX+2], 
                                    this->output_data[ACCEL1_INDEX+3]);
    outmsg.set__accel_1(accel1);
    
    
    float accel2 = convert_to_float(this->output_data[ACCEL2_INDEX], 
                                    this->output_data[ACCEL2_INDEX+1], 
                                    this->output_data[ACCEL2_INDEX+2], 
                                    this->output_data[ACCEL2_INDEX+3]);
    outmsg.set__accel_2(accel2);

    
    
    float accel3 = convert_to_float(this->output_data[ACCEL3_INDEX], 
                                    this->output_data[ACCEL3_INDEX+1], 
                                    this->output_data[ACCEL3_INDEX+2], 
                                    this->output_data[ACCEL3_INDEX+3]);
    outmsg.set__accel_3(accel3);
    
    
    float motor_abs_velocity = convert_to_float(this->output_data[MOTOR_ABS_VEL_INDEX], 
                                                this->output_data[MOTOR_ABS_VEL_INDEX+1], 
                                                this->output_data[MOTOR_ABS_VEL_INDEX+2], 
                                                this->output_data[MOTOR_ABS_VEL_INDEX+3]);
    outmsg.set__motor_abs_velocity(motor_abs_velocity);
    
    
    float motor_abs_position = convert_to_float(this->output_data[MOTOR_ABS_POS_INDEX], 
                                                this->output_data[MOTOR_ABS_POS_INDEX+1], 
                                                this->output_data[MOTOR_ABS_POS_INDEX+2], 
                                                this->output_data[MOTOR_ABS_POS_INDEX+3]);
    outmsg.set__motor_abs_position(motor_abs_position);
    
    
    float ing_bus_voltage = convert_to_float(this->output_data[BUS_VOLTAGE_INDEX], 
                                             this->output_data[BUS_VOLTAGE_INDEX+1], 
                                             this->output_data[BUS_VOLTAGE_INDEX+2], 
                                             this->output_data[BUS_VOLTAGE_INDEX+3]);
    outmsg.set__ing_bus_voltage(ing_bus_voltage);
    

    float power_stage_temp = convert_to_float(this->output_data[STAGE_TEMP_INDEX], 
                                                  this->output_data[STAGE_TEMP_INDEX+1], 
                                                  this->output_data[STAGE_TEMP_INDEX+2], 
                                                  this->output_data[STAGE_TEMP_INDEX+3]);
    outmsg.set__power_stage_temp(power_stage_temp);

    
    float motor_inc_position = convert_to_float(this->output_data[MOTOR_INC_POS_INDEX], 
                                                this->output_data[MOTOR_INC_POS_INDEX+1], 
                                                this->output_data[MOTOR_INC_POS_INDEX+2], 
                                                this->output_data[MOTOR_INC_POS_INDEX+3]);
    outmsg.set__motor_inc_position(motor_inc_position);
    

    float motor_inc_velocity = convert_to_float(this->output_data[MOTOR_INC_VEL_INDEX], 
                                                this->output_data[MOTOR_INC_VEL_INDEX+1], 
                                                this->output_data[MOTOR_INC_VEL_INDEX+2], 
                                                this->output_data[MOTOR_INC_VEL_INDEX+3]);
    outmsg.set__motor_inc_velocity(motor_inc_velocity);

    

    float des_current = convert_to_float(this->output_data[DES_CURRENT_INDEX], 
                                         this->output_data[DES_CURRENT_INDEX+1], 
                                         this->output_data[DES_CURRENT_INDEX+2], 
                                         this->output_data[DES_CURRENT_INDEX+3]);
    outmsg.set__des_current(des_current);
    

    float act_current = convert_to_float(this->output_data[ACT_CURRENT_INDEX], 
                                             this->output_data[ACT_CURRENT_INDEX+1], 
                                             this->output_data[ACT_CURRENT_INDEX+2], 
                                             this->output_data[ACT_CURRENT_INDEX+3]);
    outmsg.set__act_current(act_current);
    
    float des_torque = convert_to_float(this->output_data[DES_TORQUE_INDEX], 
                                             this->output_data[DES_TORQUE_INDEX+1], 
                                             this->output_data[DES_TORQUE_INDEX+2], 
                                             this->output_data[DES_TORQUE_INDEX+3]);
    outmsg.set__des_torque(des_torque);
    

    float error_code = convert_to_float(this->output_data[ERROR_CODE_INDEX], 
                                             this->output_data[ERROR_CODE_INDEX+1], 
                                             this->output_data[ERROR_CODE_INDEX+2], 
                                             this->output_data[ERROR_CODE_INDEX+3]);
    outmsg.set__error_code(error_code);

    float control_effort = convert_to_float(this->output_data[CONTROL_EFFORT_INDEX], 
                                                this->output_data[CONTROL_EFFORT_INDEX+1], 
                                                this->output_data[CONTROL_EFFORT_INDEX+2], 
                                                this->output_data[CONTROL_EFFORT_INDEX+3]);
    outmsg.set__control_effort(control_effort);

    this->telemetry_publisher->publish(outmsg);
}

// ================= SPI TRANSACTION =================
void Actuator_Bridge::spi_transaction()
{
    std::lock_guard<std::mutex> lock(data_mutex);

    std::memcpy(this->spi_buffer,this->input_data,SPI_BUFFER_SIZE);

    int result = wiringPiSPIDataRW(CHANNEL,this->spi_buffer,SPI_BUFFER_SIZE);

    if (result != SPI_BUFFER_SIZE)
    {
        RCLCPP_ERROR(get_logger(), "SPI transaction failed");
        return;
    }
    else
    {   
        RCLCPP_INFO(get_logger(), "Here");
        bool zero_check = false;
        if (this->spi_buffer[SPI_BUFFER_SIZE - 1] !=0 || this->spi_buffer[SPI_BUFFER_SIZE -2] != 0)
            zero_check = true;

        if (true)//(zero_check)
        {  
            
            if (true)//(verify_checksum(this->spi_buffer)) //(verify_checksum(spi_buffer))
            {
                std::memcpy(this->output_data,this->spi_buffer,SPI_BUFFER_SIZE);

                telemetry_pub_callback();
            }
        }
    }
}

// ================= HELPERS =================
/**
 * As per the original labview code, finds the check sum 1
 * that will be delivered as part of the SPI code the PIC32
 * 
 * @param data: the raw data input. a 124 length array of unsigned 16 bit integers.
 * 
 * @return the first check sum value 
 */
uint8_t Actuator_Bridge::get_checksum_1(const uint8_t* data)
{
    uint8_t c0;

    uint8_t sum1;
    uint8_t sum2;
    
    int count = SPI_BUFFER_SIZE - 2;

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
uint8_t Actuator_Bridge::get_checksum_2(const uint8_t* data)
{
    uint8_t c0;
    uint8_t c1;

    uint8_t sum1;
    uint8_t sum2;
    
    int count = SPI_BUFFER_SIZE - 2; // assume 16 bits are devoted to checksum
    

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
bool Actuator_Bridge::verify_checksum(const uint8_t* data)
{   
    // bool zero_check  = false;
    uint8_t sum1;
    uint8_t sum2;

    for(int i = 0; i < SPI_BUFFER_SIZE; ++i)
    {
        sum1 = (sum1 + data[i])%255;
        sum2 = (sum1 + sum2)%255;
    }

    return ((sum1 == 0) && (sum2 == 0));
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
int Actuator_Bridge::get_on_off_code(int service_code)
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
float Actuator_Bridge::convert_to_float(uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3)
{
    float value;
    uint8_t bytes[4] = {b3, b2, b1, b0};
    std::memcpy(&value, bytes, sizeof(value));
    return value;
}