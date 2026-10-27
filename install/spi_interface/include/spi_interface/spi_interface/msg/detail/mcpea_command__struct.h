// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from spi_interface:msg/McpeaCommand.idl
// generated code does not contain a copyright notice

#ifndef SPI_INTERFACE__MSG__DETAIL__MCPEA_COMMAND__STRUCT_H_
#define SPI_INTERFACE__MSG__DETAIL__MCPEA_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/McpeaCommand in the package spi_interface.
/**
  * MCPEA_command.msg
 */
typedef struct spi_interface__msg__McpeaCommand
{
  float torque_limit;
  float motor_state_cmd;
  float current_limit;
  float feedforward_torque;
  float control_mode;
  float data_1;
  float data_2;
  float data_3;
  float data_4;
  float data_5;
  float dynamic_comp_gain;
  bool dynamic_comp_on;
} spi_interface__msg__McpeaCommand;

// Struct for a sequence of spi_interface__msg__McpeaCommand.
typedef struct spi_interface__msg__McpeaCommand__Sequence
{
  spi_interface__msg__McpeaCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spi_interface__msg__McpeaCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPI_INTERFACE__MSG__DETAIL__MCPEA_COMMAND__STRUCT_H_
