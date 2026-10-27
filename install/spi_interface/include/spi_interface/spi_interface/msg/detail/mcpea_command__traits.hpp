// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from spi_interface:msg/McpeaCommand.idl
// generated code does not contain a copyright notice

#ifndef SPI_INTERFACE__MSG__DETAIL__MCPEA_COMMAND__TRAITS_HPP_
#define SPI_INTERFACE__MSG__DETAIL__MCPEA_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "spi_interface/msg/detail/mcpea_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace spi_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const McpeaCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: torque_limit
  {
    out << "torque_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.torque_limit, out);
    out << ", ";
  }

  // member: motor_state_cmd
  {
    out << "motor_state_cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_state_cmd, out);
    out << ", ";
  }

  // member: current_limit
  {
    out << "current_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.current_limit, out);
    out << ", ";
  }

  // member: feedforward_torque
  {
    out << "feedforward_torque: ";
    rosidl_generator_traits::value_to_yaml(msg.feedforward_torque, out);
    out << ", ";
  }

  // member: control_mode
  {
    out << "control_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.control_mode, out);
    out << ", ";
  }

  // member: data_1
  {
    out << "data_1: ";
    rosidl_generator_traits::value_to_yaml(msg.data_1, out);
    out << ", ";
  }

  // member: data_2
  {
    out << "data_2: ";
    rosidl_generator_traits::value_to_yaml(msg.data_2, out);
    out << ", ";
  }

  // member: data_3
  {
    out << "data_3: ";
    rosidl_generator_traits::value_to_yaml(msg.data_3, out);
    out << ", ";
  }

  // member: data_4
  {
    out << "data_4: ";
    rosidl_generator_traits::value_to_yaml(msg.data_4, out);
    out << ", ";
  }

  // member: data_5
  {
    out << "data_5: ";
    rosidl_generator_traits::value_to_yaml(msg.data_5, out);
    out << ", ";
  }

  // member: dynamic_comp_gain
  {
    out << "dynamic_comp_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.dynamic_comp_gain, out);
    out << ", ";
  }

  // member: dynamic_comp_on
  {
    out << "dynamic_comp_on: ";
    rosidl_generator_traits::value_to_yaml(msg.dynamic_comp_on, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const McpeaCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: torque_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "torque_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.torque_limit, out);
    out << "\n";
  }

  // member: motor_state_cmd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_state_cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_state_cmd, out);
    out << "\n";
  }

  // member: current_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.current_limit, out);
    out << "\n";
  }

  // member: feedforward_torque
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedforward_torque: ";
    rosidl_generator_traits::value_to_yaml(msg.feedforward_torque, out);
    out << "\n";
  }

  // member: control_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "control_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.control_mode, out);
    out << "\n";
  }

  // member: data_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data_1: ";
    rosidl_generator_traits::value_to_yaml(msg.data_1, out);
    out << "\n";
  }

  // member: data_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data_2: ";
    rosidl_generator_traits::value_to_yaml(msg.data_2, out);
    out << "\n";
  }

  // member: data_3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data_3: ";
    rosidl_generator_traits::value_to_yaml(msg.data_3, out);
    out << "\n";
  }

  // member: data_4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data_4: ";
    rosidl_generator_traits::value_to_yaml(msg.data_4, out);
    out << "\n";
  }

  // member: data_5
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data_5: ";
    rosidl_generator_traits::value_to_yaml(msg.data_5, out);
    out << "\n";
  }

  // member: dynamic_comp_gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dynamic_comp_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.dynamic_comp_gain, out);
    out << "\n";
  }

  // member: dynamic_comp_on
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dynamic_comp_on: ";
    rosidl_generator_traits::value_to_yaml(msg.dynamic_comp_on, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const McpeaCommand & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace spi_interface

namespace rosidl_generator_traits
{

[[deprecated("use spi_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const spi_interface::msg::McpeaCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  spi_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use spi_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const spi_interface::msg::McpeaCommand & msg)
{
  return spi_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<spi_interface::msg::McpeaCommand>()
{
  return "spi_interface::msg::McpeaCommand";
}

template<>
inline const char * name<spi_interface::msg::McpeaCommand>()
{
  return "spi_interface/msg/McpeaCommand";
}

template<>
struct has_fixed_size<spi_interface::msg::McpeaCommand>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<spi_interface::msg::McpeaCommand>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<spi_interface::msg::McpeaCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SPI_INTERFACE__MSG__DETAIL__MCPEA_COMMAND__TRAITS_HPP_
