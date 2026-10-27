// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from spi_interface:msg/McpeaTelemetry.idl
// generated code does not contain a copyright notice

#ifndef SPI_INTERFACE__MSG__DETAIL__MCPEA_TELEMETRY__STRUCT_HPP_
#define SPI_INTERFACE__MSG__DETAIL__MCPEA_TELEMETRY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__spi_interface__msg__McpeaTelemetry __attribute__((deprecated))
#else
# define DEPRECATED__spi_interface__msg__McpeaTelemetry __declspec(deprecated)
#endif

namespace spi_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct McpeaTelemetry_
{
  using Type = McpeaTelemetry_<ContainerAllocator>;

  explicit McpeaTelemetry_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accel_1 = 0.0f;
      this->accel_2 = 0.0f;
      this->accel_3 = 0.0f;
      this->motor_abs_velocity = 0.0f;
      this->motor_abs_position = 0.0f;
      this->ing_bus_voltage = 0.0f;
      this->power_stage_temp = 0.0f;
      this->motor_inc_position = 0.0f;
      this->motor_inc_velocity = 0.0f;
      this->joint_position = 0.0f;
      this->joint_velocity = 0.0f;
      this->des_current = 0.0f;
      this->act_current = 0.0f;
      this->des_torque = 0.0f;
      this->control_effort = 0.0f;
      this->boom_angle = 0.0f;
      this->error_code = 0.0f;
    }
  }

  explicit McpeaTelemetry_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accel_1 = 0.0f;
      this->accel_2 = 0.0f;
      this->accel_3 = 0.0f;
      this->motor_abs_velocity = 0.0f;
      this->motor_abs_position = 0.0f;
      this->ing_bus_voltage = 0.0f;
      this->power_stage_temp = 0.0f;
      this->motor_inc_position = 0.0f;
      this->motor_inc_velocity = 0.0f;
      this->joint_position = 0.0f;
      this->joint_velocity = 0.0f;
      this->des_current = 0.0f;
      this->act_current = 0.0f;
      this->des_torque = 0.0f;
      this->control_effort = 0.0f;
      this->boom_angle = 0.0f;
      this->error_code = 0.0f;
    }
  }

  // field types and members
  using _accel_1_type =
    float;
  _accel_1_type accel_1;
  using _accel_2_type =
    float;
  _accel_2_type accel_2;
  using _accel_3_type =
    float;
  _accel_3_type accel_3;
  using _motor_abs_velocity_type =
    float;
  _motor_abs_velocity_type motor_abs_velocity;
  using _motor_abs_position_type =
    float;
  _motor_abs_position_type motor_abs_position;
  using _ing_bus_voltage_type =
    float;
  _ing_bus_voltage_type ing_bus_voltage;
  using _power_stage_temp_type =
    float;
  _power_stage_temp_type power_stage_temp;
  using _motor_inc_position_type =
    float;
  _motor_inc_position_type motor_inc_position;
  using _motor_inc_velocity_type =
    float;
  _motor_inc_velocity_type motor_inc_velocity;
  using _joint_position_type =
    float;
  _joint_position_type joint_position;
  using _joint_velocity_type =
    float;
  _joint_velocity_type joint_velocity;
  using _des_current_type =
    float;
  _des_current_type des_current;
  using _act_current_type =
    float;
  _act_current_type act_current;
  using _des_torque_type =
    float;
  _des_torque_type des_torque;
  using _control_effort_type =
    float;
  _control_effort_type control_effort;
  using _boom_angle_type =
    float;
  _boom_angle_type boom_angle;
  using _error_code_type =
    float;
  _error_code_type error_code;

  // setters for named parameter idiom
  Type & set__accel_1(
    const float & _arg)
  {
    this->accel_1 = _arg;
    return *this;
  }
  Type & set__accel_2(
    const float & _arg)
  {
    this->accel_2 = _arg;
    return *this;
  }
  Type & set__accel_3(
    const float & _arg)
  {
    this->accel_3 = _arg;
    return *this;
  }
  Type & set__motor_abs_velocity(
    const float & _arg)
  {
    this->motor_abs_velocity = _arg;
    return *this;
  }
  Type & set__motor_abs_position(
    const float & _arg)
  {
    this->motor_abs_position = _arg;
    return *this;
  }
  Type & set__ing_bus_voltage(
    const float & _arg)
  {
    this->ing_bus_voltage = _arg;
    return *this;
  }
  Type & set__power_stage_temp(
    const float & _arg)
  {
    this->power_stage_temp = _arg;
    return *this;
  }
  Type & set__motor_inc_position(
    const float & _arg)
  {
    this->motor_inc_position = _arg;
    return *this;
  }
  Type & set__motor_inc_velocity(
    const float & _arg)
  {
    this->motor_inc_velocity = _arg;
    return *this;
  }
  Type & set__joint_position(
    const float & _arg)
  {
    this->joint_position = _arg;
    return *this;
  }
  Type & set__joint_velocity(
    const float & _arg)
  {
    this->joint_velocity = _arg;
    return *this;
  }
  Type & set__des_current(
    const float & _arg)
  {
    this->des_current = _arg;
    return *this;
  }
  Type & set__act_current(
    const float & _arg)
  {
    this->act_current = _arg;
    return *this;
  }
  Type & set__des_torque(
    const float & _arg)
  {
    this->des_torque = _arg;
    return *this;
  }
  Type & set__control_effort(
    const float & _arg)
  {
    this->control_effort = _arg;
    return *this;
  }
  Type & set__boom_angle(
    const float & _arg)
  {
    this->boom_angle = _arg;
    return *this;
  }
  Type & set__error_code(
    const float & _arg)
  {
    this->error_code = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    spi_interface::msg::McpeaTelemetry_<ContainerAllocator> *;
  using ConstRawPtr =
    const spi_interface::msg::McpeaTelemetry_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spi_interface::msg::McpeaTelemetry_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spi_interface::msg::McpeaTelemetry_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spi_interface::msg::McpeaTelemetry_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spi_interface::msg::McpeaTelemetry_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spi_interface::msg::McpeaTelemetry_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spi_interface::msg::McpeaTelemetry_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spi_interface::msg::McpeaTelemetry_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spi_interface::msg::McpeaTelemetry_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spi_interface__msg__McpeaTelemetry
    std::shared_ptr<spi_interface::msg::McpeaTelemetry_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spi_interface__msg__McpeaTelemetry
    std::shared_ptr<spi_interface::msg::McpeaTelemetry_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const McpeaTelemetry_ & other) const
  {
    if (this->accel_1 != other.accel_1) {
      return false;
    }
    if (this->accel_2 != other.accel_2) {
      return false;
    }
    if (this->accel_3 != other.accel_3) {
      return false;
    }
    if (this->motor_abs_velocity != other.motor_abs_velocity) {
      return false;
    }
    if (this->motor_abs_position != other.motor_abs_position) {
      return false;
    }
    if (this->ing_bus_voltage != other.ing_bus_voltage) {
      return false;
    }
    if (this->power_stage_temp != other.power_stage_temp) {
      return false;
    }
    if (this->motor_inc_position != other.motor_inc_position) {
      return false;
    }
    if (this->motor_inc_velocity != other.motor_inc_velocity) {
      return false;
    }
    if (this->joint_position != other.joint_position) {
      return false;
    }
    if (this->joint_velocity != other.joint_velocity) {
      return false;
    }
    if (this->des_current != other.des_current) {
      return false;
    }
    if (this->act_current != other.act_current) {
      return false;
    }
    if (this->des_torque != other.des_torque) {
      return false;
    }
    if (this->control_effort != other.control_effort) {
      return false;
    }
    if (this->boom_angle != other.boom_angle) {
      return false;
    }
    if (this->error_code != other.error_code) {
      return false;
    }
    return true;
  }
  bool operator!=(const McpeaTelemetry_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct McpeaTelemetry_

// alias to use template instance with default allocator
using McpeaTelemetry =
  spi_interface::msg::McpeaTelemetry_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace spi_interface

#endif  // SPI_INTERFACE__MSG__DETAIL__MCPEA_TELEMETRY__STRUCT_HPP_
