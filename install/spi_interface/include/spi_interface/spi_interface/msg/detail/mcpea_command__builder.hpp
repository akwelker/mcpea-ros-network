// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from spi_interface:msg/McpeaCommand.idl
// generated code does not contain a copyright notice

#ifndef SPI_INTERFACE__MSG__DETAIL__MCPEA_COMMAND__BUILDER_HPP_
#define SPI_INTERFACE__MSG__DETAIL__MCPEA_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "spi_interface/msg/detail/mcpea_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace spi_interface
{

namespace msg
{

namespace builder
{

class Init_McpeaCommand_dynamic_comp_on
{
public:
  explicit Init_McpeaCommand_dynamic_comp_on(::spi_interface::msg::McpeaCommand & msg)
  : msg_(msg)
  {}
  ::spi_interface::msg::McpeaCommand dynamic_comp_on(::spi_interface::msg::McpeaCommand::_dynamic_comp_on_type arg)
  {
    msg_.dynamic_comp_on = std::move(arg);
    return std::move(msg_);
  }

private:
  ::spi_interface::msg::McpeaCommand msg_;
};

class Init_McpeaCommand_dynamic_comp_gain
{
public:
  explicit Init_McpeaCommand_dynamic_comp_gain(::spi_interface::msg::McpeaCommand & msg)
  : msg_(msg)
  {}
  Init_McpeaCommand_dynamic_comp_on dynamic_comp_gain(::spi_interface::msg::McpeaCommand::_dynamic_comp_gain_type arg)
  {
    msg_.dynamic_comp_gain = std::move(arg);
    return Init_McpeaCommand_dynamic_comp_on(msg_);
  }

private:
  ::spi_interface::msg::McpeaCommand msg_;
};

class Init_McpeaCommand_data_5
{
public:
  explicit Init_McpeaCommand_data_5(::spi_interface::msg::McpeaCommand & msg)
  : msg_(msg)
  {}
  Init_McpeaCommand_dynamic_comp_gain data_5(::spi_interface::msg::McpeaCommand::_data_5_type arg)
  {
    msg_.data_5 = std::move(arg);
    return Init_McpeaCommand_dynamic_comp_gain(msg_);
  }

private:
  ::spi_interface::msg::McpeaCommand msg_;
};

class Init_McpeaCommand_data_4
{
public:
  explicit Init_McpeaCommand_data_4(::spi_interface::msg::McpeaCommand & msg)
  : msg_(msg)
  {}
  Init_McpeaCommand_data_5 data_4(::spi_interface::msg::McpeaCommand::_data_4_type arg)
  {
    msg_.data_4 = std::move(arg);
    return Init_McpeaCommand_data_5(msg_);
  }

private:
  ::spi_interface::msg::McpeaCommand msg_;
};

class Init_McpeaCommand_data_3
{
public:
  explicit Init_McpeaCommand_data_3(::spi_interface::msg::McpeaCommand & msg)
  : msg_(msg)
  {}
  Init_McpeaCommand_data_4 data_3(::spi_interface::msg::McpeaCommand::_data_3_type arg)
  {
    msg_.data_3 = std::move(arg);
    return Init_McpeaCommand_data_4(msg_);
  }

private:
  ::spi_interface::msg::McpeaCommand msg_;
};

class Init_McpeaCommand_data_2
{
public:
  explicit Init_McpeaCommand_data_2(::spi_interface::msg::McpeaCommand & msg)
  : msg_(msg)
  {}
  Init_McpeaCommand_data_3 data_2(::spi_interface::msg::McpeaCommand::_data_2_type arg)
  {
    msg_.data_2 = std::move(arg);
    return Init_McpeaCommand_data_3(msg_);
  }

private:
  ::spi_interface::msg::McpeaCommand msg_;
};

class Init_McpeaCommand_data_1
{
public:
  explicit Init_McpeaCommand_data_1(::spi_interface::msg::McpeaCommand & msg)
  : msg_(msg)
  {}
  Init_McpeaCommand_data_2 data_1(::spi_interface::msg::McpeaCommand::_data_1_type arg)
  {
    msg_.data_1 = std::move(arg);
    return Init_McpeaCommand_data_2(msg_);
  }

private:
  ::spi_interface::msg::McpeaCommand msg_;
};

class Init_McpeaCommand_control_mode
{
public:
  explicit Init_McpeaCommand_control_mode(::spi_interface::msg::McpeaCommand & msg)
  : msg_(msg)
  {}
  Init_McpeaCommand_data_1 control_mode(::spi_interface::msg::McpeaCommand::_control_mode_type arg)
  {
    msg_.control_mode = std::move(arg);
    return Init_McpeaCommand_data_1(msg_);
  }

private:
  ::spi_interface::msg::McpeaCommand msg_;
};

class Init_McpeaCommand_feedforward_torque
{
public:
  explicit Init_McpeaCommand_feedforward_torque(::spi_interface::msg::McpeaCommand & msg)
  : msg_(msg)
  {}
  Init_McpeaCommand_control_mode feedforward_torque(::spi_interface::msg::McpeaCommand::_feedforward_torque_type arg)
  {
    msg_.feedforward_torque = std::move(arg);
    return Init_McpeaCommand_control_mode(msg_);
  }

private:
  ::spi_interface::msg::McpeaCommand msg_;
};

class Init_McpeaCommand_current_limit
{
public:
  explicit Init_McpeaCommand_current_limit(::spi_interface::msg::McpeaCommand & msg)
  : msg_(msg)
  {}
  Init_McpeaCommand_feedforward_torque current_limit(::spi_interface::msg::McpeaCommand::_current_limit_type arg)
  {
    msg_.current_limit = std::move(arg);
    return Init_McpeaCommand_feedforward_torque(msg_);
  }

private:
  ::spi_interface::msg::McpeaCommand msg_;
};

class Init_McpeaCommand_motor_state_cmd
{
public:
  explicit Init_McpeaCommand_motor_state_cmd(::spi_interface::msg::McpeaCommand & msg)
  : msg_(msg)
  {}
  Init_McpeaCommand_current_limit motor_state_cmd(::spi_interface::msg::McpeaCommand::_motor_state_cmd_type arg)
  {
    msg_.motor_state_cmd = std::move(arg);
    return Init_McpeaCommand_current_limit(msg_);
  }

private:
  ::spi_interface::msg::McpeaCommand msg_;
};

class Init_McpeaCommand_torque_limit
{
public:
  Init_McpeaCommand_torque_limit()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_McpeaCommand_motor_state_cmd torque_limit(::spi_interface::msg::McpeaCommand::_torque_limit_type arg)
  {
    msg_.torque_limit = std::move(arg);
    return Init_McpeaCommand_motor_state_cmd(msg_);
  }

private:
  ::spi_interface::msg::McpeaCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::spi_interface::msg::McpeaCommand>()
{
  return spi_interface::msg::builder::Init_McpeaCommand_torque_limit();
}

}  // namespace spi_interface

#endif  // SPI_INTERFACE__MSG__DETAIL__MCPEA_COMMAND__BUILDER_HPP_
