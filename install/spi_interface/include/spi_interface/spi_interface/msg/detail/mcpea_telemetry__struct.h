// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from spi_interface:msg/McpeaTelemetry.idl
// generated code does not contain a copyright notice

#ifndef SPI_INTERFACE__MSG__DETAIL__MCPEA_TELEMETRY__STRUCT_H_
#define SPI_INTERFACE__MSG__DETAIL__MCPEA_TELEMETRY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/McpeaTelemetry in the package spi_interface.
/**
  * MCPEA_Telemetry.msg
 */
typedef struct spi_interface__msg__McpeaTelemetry
{
  float accel_1;
  float accel_2;
  float accel_3;
  float motor_abs_velocity;
  float motor_abs_position;
  float ing_bus_voltage;
  float power_stage_temp;
  float motor_inc_position;
  float motor_inc_velocity;
  float joint_position;
  float joint_velocity;
  float des_current;
  float act_current;
  float des_torque;
  float control_effort;
  float boom_angle;
  float error_code;
} spi_interface__msg__McpeaTelemetry;

// Struct for a sequence of spi_interface__msg__McpeaTelemetry.
typedef struct spi_interface__msg__McpeaTelemetry__Sequence
{
  spi_interface__msg__McpeaTelemetry * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} spi_interface__msg__McpeaTelemetry__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPI_INTERFACE__MSG__DETAIL__MCPEA_TELEMETRY__STRUCT_H_
