// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from spi_interface:msg/McpeaTelemetry.idl
// generated code does not contain a copyright notice

#ifndef SPI_INTERFACE__MSG__DETAIL__MCPEA_TELEMETRY__TRAITS_HPP_
#define SPI_INTERFACE__MSG__DETAIL__MCPEA_TELEMETRY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "spi_interface/msg/detail/mcpea_telemetry__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace spi_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const McpeaTelemetry & msg,
  std::ostream & out)
{
  out << "{";
  // member: accel_1
  {
    out << "accel_1: ";
    rosidl_generator_traits::value_to_yaml(msg.accel_1, out);
    out << ", ";
  }

  // member: accel_2
  {
    out << "accel_2: ";
    rosidl_generator_traits::value_to_yaml(msg.accel_2, out);
    out << ", ";
  }

  // member: accel_3
  {
    out << "accel_3: ";
    rosidl_generator_traits::value_to_yaml(msg.accel_3, out);
    out << ", ";
  }

  // member: motor_abs_velocity
  {
    out << "motor_abs_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_abs_velocity, out);
    out << ", ";
  }

  // member: motor_abs_position
  {
    out << "motor_abs_position: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_abs_position, out);
    out << ", ";
  }

  // member: ing_bus_voltage
  {
    out << "ing_bus_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.ing_bus_voltage, out);
    out << ", ";
  }

  // member: power_stage_temp
  {
    out << "power_stage_temp: ";
    rosidl_generator_traits::value_to_yaml(msg.power_stage_temp, out);
    out << ", ";
  }

  // member: motor_inc_position
  {
    out << "motor_inc_position: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_inc_position, out);
    out << ", ";
  }

  // member: motor_inc_velocity
  {
    out << "motor_inc_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_inc_velocity, out);
    out << ", ";
  }

  // member: joint_position
  {
    out << "joint_position: ";
    rosidl_generator_traits::value_to_yaml(msg.joint_position, out);
    out << ", ";
  }

  // member: joint_velocity
  {
    out << "joint_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.joint_velocity, out);
    out << ", ";
  }

  // member: des_current
  {
    out << "des_current: ";
    rosidl_generator_traits::value_to_yaml(msg.des_current, out);
    out << ", ";
  }

  // member: act_current
  {
    out << "act_current: ";
    rosidl_generator_traits::value_to_yaml(msg.act_current, out);
    out << ", ";
  }

  // member: des_torque
  {
    out << "des_torque: ";
    rosidl_generator_traits::value_to_yaml(msg.des_torque, out);
    out << ", ";
  }

  // member: control_effort
  {
    out << "control_effort: ";
    rosidl_generator_traits::value_to_yaml(msg.control_effort, out);
    out << ", ";
  }

  // member: boom_angle
  {
    out << "boom_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.boom_angle, out);
    out << ", ";
  }

  // member: error_code
  {
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const McpeaTelemetry & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accel_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accel_1: ";
    rosidl_generator_traits::value_to_yaml(msg.accel_1, out);
    out << "\n";
  }

  // member: accel_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accel_2: ";
    rosidl_generator_traits::value_to_yaml(msg.accel_2, out);
    out << "\n";
  }

  // member: accel_3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accel_3: ";
    rosidl_generator_traits::value_to_yaml(msg.accel_3, out);
    out << "\n";
  }

  // member: motor_abs_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_abs_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_abs_velocity, out);
    out << "\n";
  }

  // member: motor_abs_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_abs_position: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_abs_position, out);
    out << "\n";
  }

  // member: ing_bus_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ing_bus_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.ing_bus_voltage, out);
    out << "\n";
  }

  // member: power_stage_temp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "power_stage_temp: ";
    rosidl_generator_traits::value_to_yaml(msg.power_stage_temp, out);
    out << "\n";
  }

  // member: motor_inc_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_inc_position: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_inc_position, out);
    out << "\n";
  }

  // member: motor_inc_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_inc_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_inc_velocity, out);
    out << "\n";
  }

  // member: joint_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "joint_position: ";
    rosidl_generator_traits::value_to_yaml(msg.joint_position, out);
    out << "\n";
  }

  // member: joint_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "joint_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.joint_velocity, out);
    out << "\n";
  }

  // member: des_current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "des_current: ";
    rosidl_generator_traits::value_to_yaml(msg.des_current, out);
    out << "\n";
  }

  // member: act_current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "act_current: ";
    rosidl_generator_traits::value_to_yaml(msg.act_current, out);
    out << "\n";
  }

  // member: des_torque
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "des_torque: ";
    rosidl_generator_traits::value_to_yaml(msg.des_torque, out);
    out << "\n";
  }

  // member: control_effort
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "control_effort: ";
    rosidl_generator_traits::value_to_yaml(msg.control_effort, out);
    out << "\n";
  }

  // member: boom_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "boom_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.boom_angle, out);
    out << "\n";
  }

  // member: error_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const McpeaTelemetry & msg, bool use_flow_style = false)
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
  const spi_interface::msg::McpeaTelemetry & msg,
  std::ostream & out, size_t indentation = 0)
{
  spi_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use spi_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const spi_interface::msg::McpeaTelemetry & msg)
{
  return spi_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<spi_interface::msg::McpeaTelemetry>()
{
  return "spi_interface::msg::McpeaTelemetry";
}

template<>
inline const char * name<spi_interface::msg::McpeaTelemetry>()
{
  return "spi_interface/msg/McpeaTelemetry";
}

template<>
struct has_fixed_size<spi_interface::msg::McpeaTelemetry>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<spi_interface::msg::McpeaTelemetry>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<spi_interface::msg::McpeaTelemetry>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SPI_INTERFACE__MSG__DETAIL__MCPEA_TELEMETRY__TRAITS_HPP_
