// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from spi_interface:msg/McpeaTelemetry.idl
// generated code does not contain a copyright notice

#ifndef SPI_INTERFACE__MSG__DETAIL__MCPEA_TELEMETRY__BUILDER_HPP_
#define SPI_INTERFACE__MSG__DETAIL__MCPEA_TELEMETRY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "spi_interface/msg/detail/mcpea_telemetry__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace spi_interface
{

namespace msg
{

namespace builder
{

class Init_McpeaTelemetry_error_code
{
public:
  explicit Init_McpeaTelemetry_error_code(::spi_interface::msg::McpeaTelemetry & msg)
  : msg_(msg)
  {}
  ::spi_interface::msg::McpeaTelemetry error_code(::spi_interface::msg::McpeaTelemetry::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spi_interface::msg::McpeaTelemetry msg_;
};

class Init_McpeaTelemetry_boom_angle
{
public:
  explicit Init_McpeaTelemetry_boom_angle(::spi_interface::msg::McpeaTelemetry & msg)
  : msg_(msg)
  {}
  Init_McpeaTelemetry_error_code boom_angle(::spi_interface::msg::McpeaTelemetry::_boom_angle_type arg)
  {
    msg_.boom_angle = std::move(arg);
    return Init_McpeaTelemetry_error_code(msg_);
  }

private:
  ::spi_interface::msg::McpeaTelemetry msg_;
};

class Init_McpeaTelemetry_control_effort
{
public:
  explicit Init_McpeaTelemetry_control_effort(::spi_interface::msg::McpeaTelemetry & msg)
  : msg_(msg)
  {}
  Init_McpeaTelemetry_boom_angle control_effort(::spi_interface::msg::McpeaTelemetry::_control_effort_type arg)
  {
    msg_.control_effort = std::move(arg);
    return Init_McpeaTelemetry_boom_angle(msg_);
  }

private:
  ::spi_interface::msg::McpeaTelemetry msg_;
};

class Init_McpeaTelemetry_des_torque
{
public:
  explicit Init_McpeaTelemetry_des_torque(::spi_interface::msg::McpeaTelemetry & msg)
  : msg_(msg)
  {}
  Init_McpeaTelemetry_control_effort des_torque(::spi_interface::msg::McpeaTelemetry::_des_torque_type arg)
  {
    msg_.des_torque = std::move(arg);
    return Init_McpeaTelemetry_control_effort(msg_);
  }

private:
  ::spi_interface::msg::McpeaTelemetry msg_;
};

class Init_McpeaTelemetry_act_current
{
public:
  explicit Init_McpeaTelemetry_act_current(::spi_interface::msg::McpeaTelemetry & msg)
  : msg_(msg)
  {}
  Init_McpeaTelemetry_des_torque act_current(::spi_interface::msg::McpeaTelemetry::_act_current_type arg)
  {
    msg_.act_current = std::move(arg);
    return Init_McpeaTelemetry_des_torque(msg_);
  }

private:
  ::spi_interface::msg::McpeaTelemetry msg_;
};

class Init_McpeaTelemetry_des_current
{
public:
  explicit Init_McpeaTelemetry_des_current(::spi_interface::msg::McpeaTelemetry & msg)
  : msg_(msg)
  {}
  Init_McpeaTelemetry_act_current des_current(::spi_interface::msg::McpeaTelemetry::_des_current_type arg)
  {
    msg_.des_current = std::move(arg);
    return Init_McpeaTelemetry_act_current(msg_);
  }

private:
  ::spi_interface::msg::McpeaTelemetry msg_;
};

class Init_McpeaTelemetry_joint_velocity
{
public:
  explicit Init_McpeaTelemetry_joint_velocity(::spi_interface::msg::McpeaTelemetry & msg)
  : msg_(msg)
  {}
  Init_McpeaTelemetry_des_current joint_velocity(::spi_interface::msg::McpeaTelemetry::_joint_velocity_type arg)
  {
    msg_.joint_velocity = std::move(arg);
    return Init_McpeaTelemetry_des_current(msg_);
  }

private:
  ::spi_interface::msg::McpeaTelemetry msg_;
};

class Init_McpeaTelemetry_joint_position
{
public:
  explicit Init_McpeaTelemetry_joint_position(::spi_interface::msg::McpeaTelemetry & msg)
  : msg_(msg)
  {}
  Init_McpeaTelemetry_joint_velocity joint_position(::spi_interface::msg::McpeaTelemetry::_joint_position_type arg)
  {
    msg_.joint_position = std::move(arg);
    return Init_McpeaTelemetry_joint_velocity(msg_);
  }

private:
  ::spi_interface::msg::McpeaTelemetry msg_;
};

class Init_McpeaTelemetry_motor_inc_velocity
{
public:
  explicit Init_McpeaTelemetry_motor_inc_velocity(::spi_interface::msg::McpeaTelemetry & msg)
  : msg_(msg)
  {}
  Init_McpeaTelemetry_joint_position motor_inc_velocity(::spi_interface::msg::McpeaTelemetry::_motor_inc_velocity_type arg)
  {
    msg_.motor_inc_velocity = std::move(arg);
    return Init_McpeaTelemetry_joint_position(msg_);
  }

private:
  ::spi_interface::msg::McpeaTelemetry msg_;
};

class Init_McpeaTelemetry_motor_inc_position
{
public:
  explicit Init_McpeaTelemetry_motor_inc_position(::spi_interface::msg::McpeaTelemetry & msg)
  : msg_(msg)
  {}
  Init_McpeaTelemetry_motor_inc_velocity motor_inc_position(::spi_interface::msg::McpeaTelemetry::_motor_inc_position_type arg)
  {
    msg_.motor_inc_position = std::move(arg);
    return Init_McpeaTelemetry_motor_inc_velocity(msg_);
  }

private:
  ::spi_interface::msg::McpeaTelemetry msg_;
};

class Init_McpeaTelemetry_power_stage_temp
{
public:
  explicit Init_McpeaTelemetry_power_stage_temp(::spi_interface::msg::McpeaTelemetry & msg)
  : msg_(msg)
  {}
  Init_McpeaTelemetry_motor_inc_position power_stage_temp(::spi_interface::msg::McpeaTelemetry::_power_stage_temp_type arg)
  {
    msg_.power_stage_temp = std::move(arg);
    return Init_McpeaTelemetry_motor_inc_position(msg_);
  }

private:
  ::spi_interface::msg::McpeaTelemetry msg_;
};

class Init_McpeaTelemetry_ing_bus_voltage
{
public:
  explicit Init_McpeaTelemetry_ing_bus_voltage(::spi_interface::msg::McpeaTelemetry & msg)
  : msg_(msg)
  {}
  Init_McpeaTelemetry_power_stage_temp ing_bus_voltage(::spi_interface::msg::McpeaTelemetry::_ing_bus_voltage_type arg)
  {
    msg_.ing_bus_voltage = std::move(arg);
    return Init_McpeaTelemetry_power_stage_temp(msg_);
  }

private:
  ::spi_interface::msg::McpeaTelemetry msg_;
};

class Init_McpeaTelemetry_motor_abs_position
{
public:
  explicit Init_McpeaTelemetry_motor_abs_position(::spi_interface::msg::McpeaTelemetry & msg)
  : msg_(msg)
  {}
  Init_McpeaTelemetry_ing_bus_voltage motor_abs_position(::spi_interface::msg::McpeaTelemetry::_motor_abs_position_type arg)
  {
    msg_.motor_abs_position = std::move(arg);
    return Init_McpeaTelemetry_ing_bus_voltage(msg_);
  }

private:
  ::spi_interface::msg::McpeaTelemetry msg_;
};

class Init_McpeaTelemetry_motor_abs_velocity
{
public:
  explicit Init_McpeaTelemetry_motor_abs_velocity(::spi_interface::msg::McpeaTelemetry & msg)
  : msg_(msg)
  {}
  Init_McpeaTelemetry_motor_abs_position motor_abs_velocity(::spi_interface::msg::McpeaTelemetry::_motor_abs_velocity_type arg)
  {
    msg_.motor_abs_velocity = std::move(arg);
    return Init_McpeaTelemetry_motor_abs_position(msg_);
  }

private:
  ::spi_interface::msg::McpeaTelemetry msg_;
};

class Init_McpeaTelemetry_accel_3
{
public:
  explicit Init_McpeaTelemetry_accel_3(::spi_interface::msg::McpeaTelemetry & msg)
  : msg_(msg)
  {}
  Init_McpeaTelemetry_motor_abs_velocity accel_3(::spi_interface::msg::McpeaTelemetry::_accel_3_type arg)
  {
    msg_.accel_3 = std::move(arg);
    return Init_McpeaTelemetry_motor_abs_velocity(msg_);
  }

private:
  ::spi_interface::msg::McpeaTelemetry msg_;
};

class Init_McpeaTelemetry_accel_2
{
public:
  explicit Init_McpeaTelemetry_accel_2(::spi_interface::msg::McpeaTelemetry & msg)
  : msg_(msg)
  {}
  Init_McpeaTelemetry_accel_3 accel_2(::spi_interface::msg::McpeaTelemetry::_accel_2_type arg)
  {
    msg_.accel_2 = std::move(arg);
    return Init_McpeaTelemetry_accel_3(msg_);
  }

private:
  ::spi_interface::msg::McpeaTelemetry msg_;
};

class Init_McpeaTelemetry_accel_1
{
public:
  Init_McpeaTelemetry_accel_1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_McpeaTelemetry_accel_2 accel_1(::spi_interface::msg::McpeaTelemetry::_accel_1_type arg)
  {
    msg_.accel_1 = std::move(arg);
    return Init_McpeaTelemetry_accel_2(msg_);
  }

private:
  ::spi_interface::msg::McpeaTelemetry msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::spi_interface::msg::McpeaTelemetry>()
{
  return spi_interface::msg::builder::Init_McpeaTelemetry_accel_1();
}

}  // namespace spi_interface

#endif  // SPI_INTERFACE__MSG__DETAIL__MCPEA_TELEMETRY__BUILDER_HPP_
