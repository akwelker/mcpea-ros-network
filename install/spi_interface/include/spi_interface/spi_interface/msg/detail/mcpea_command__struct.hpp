// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from spi_interface:msg/McpeaCommand.idl
// generated code does not contain a copyright notice

#ifndef SPI_INTERFACE__MSG__DETAIL__MCPEA_COMMAND__STRUCT_HPP_
#define SPI_INTERFACE__MSG__DETAIL__MCPEA_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__spi_interface__msg__McpeaCommand __attribute__((deprecated))
#else
# define DEPRECATED__spi_interface__msg__McpeaCommand __declspec(deprecated)
#endif

namespace spi_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct McpeaCommand_
{
  using Type = McpeaCommand_<ContainerAllocator>;

  explicit McpeaCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->torque_limit = 0.0f;
      this->motor_state_cmd = 0.0f;
      this->current_limit = 0.0f;
      this->feedforward_torque = 0.0f;
      this->control_mode = 0.0f;
      this->data_1 = 0.0f;
      this->data_2 = 0.0f;
      this->data_3 = 0.0f;
      this->data_4 = 0.0f;
      this->data_5 = 0.0f;
      this->dynamic_comp_gain = 0.0f;
      this->dynamic_comp_on = false;
    }
  }

  explicit McpeaCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->torque_limit = 0.0f;
      this->motor_state_cmd = 0.0f;
      this->current_limit = 0.0f;
      this->feedforward_torque = 0.0f;
      this->control_mode = 0.0f;
      this->data_1 = 0.0f;
      this->data_2 = 0.0f;
      this->data_3 = 0.0f;
      this->data_4 = 0.0f;
      this->data_5 = 0.0f;
      this->dynamic_comp_gain = 0.0f;
      this->dynamic_comp_on = false;
    }
  }

  // field types and members
  using _torque_limit_type =
    float;
  _torque_limit_type torque_limit;
  using _motor_state_cmd_type =
    float;
  _motor_state_cmd_type motor_state_cmd;
  using _current_limit_type =
    float;
  _current_limit_type current_limit;
  using _feedforward_torque_type =
    float;
  _feedforward_torque_type feedforward_torque;
  using _control_mode_type =
    float;
  _control_mode_type control_mode;
  using _data_1_type =
    float;
  _data_1_type data_1;
  using _data_2_type =
    float;
  _data_2_type data_2;
  using _data_3_type =
    float;
  _data_3_type data_3;
  using _data_4_type =
    float;
  _data_4_type data_4;
  using _data_5_type =
    float;
  _data_5_type data_5;
  using _dynamic_comp_gain_type =
    float;
  _dynamic_comp_gain_type dynamic_comp_gain;
  using _dynamic_comp_on_type =
    bool;
  _dynamic_comp_on_type dynamic_comp_on;

  // setters for named parameter idiom
  Type & set__torque_limit(
    const float & _arg)
  {
    this->torque_limit = _arg;
    return *this;
  }
  Type & set__motor_state_cmd(
    const float & _arg)
  {
    this->motor_state_cmd = _arg;
    return *this;
  }
  Type & set__current_limit(
    const float & _arg)
  {
    this->current_limit = _arg;
    return *this;
  }
  Type & set__feedforward_torque(
    const float & _arg)
  {
    this->feedforward_torque = _arg;
    return *this;
  }
  Type & set__control_mode(
    const float & _arg)
  {
    this->control_mode = _arg;
    return *this;
  }
  Type & set__data_1(
    const float & _arg)
  {
    this->data_1 = _arg;
    return *this;
  }
  Type & set__data_2(
    const float & _arg)
  {
    this->data_2 = _arg;
    return *this;
  }
  Type & set__data_3(
    const float & _arg)
  {
    this->data_3 = _arg;
    return *this;
  }
  Type & set__data_4(
    const float & _arg)
  {
    this->data_4 = _arg;
    return *this;
  }
  Type & set__data_5(
    const float & _arg)
  {
    this->data_5 = _arg;
    return *this;
  }
  Type & set__dynamic_comp_gain(
    const float & _arg)
  {
    this->dynamic_comp_gain = _arg;
    return *this;
  }
  Type & set__dynamic_comp_on(
    const bool & _arg)
  {
    this->dynamic_comp_on = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    spi_interface::msg::McpeaCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const spi_interface::msg::McpeaCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<spi_interface::msg::McpeaCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<spi_interface::msg::McpeaCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      spi_interface::msg::McpeaCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<spi_interface::msg::McpeaCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      spi_interface::msg::McpeaCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<spi_interface::msg::McpeaCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<spi_interface::msg::McpeaCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<spi_interface::msg::McpeaCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__spi_interface__msg__McpeaCommand
    std::shared_ptr<spi_interface::msg::McpeaCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__spi_interface__msg__McpeaCommand
    std::shared_ptr<spi_interface::msg::McpeaCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const McpeaCommand_ & other) const
  {
    if (this->torque_limit != other.torque_limit) {
      return false;
    }
    if (this->motor_state_cmd != other.motor_state_cmd) {
      return false;
    }
    if (this->current_limit != other.current_limit) {
      return false;
    }
    if (this->feedforward_torque != other.feedforward_torque) {
      return false;
    }
    if (this->control_mode != other.control_mode) {
      return false;
    }
    if (this->data_1 != other.data_1) {
      return false;
    }
    if (this->data_2 != other.data_2) {
      return false;
    }
    if (this->data_3 != other.data_3) {
      return false;
    }
    if (this->data_4 != other.data_4) {
      return false;
    }
    if (this->data_5 != other.data_5) {
      return false;
    }
    if (this->dynamic_comp_gain != other.dynamic_comp_gain) {
      return false;
    }
    if (this->dynamic_comp_on != other.dynamic_comp_on) {
      return false;
    }
    return true;
  }
  bool operator!=(const McpeaCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct McpeaCommand_

// alias to use template instance with default allocator
using McpeaCommand =
  spi_interface::msg::McpeaCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace spi_interface

#endif  // SPI_INTERFACE__MSG__DETAIL__MCPEA_COMMAND__STRUCT_HPP_
