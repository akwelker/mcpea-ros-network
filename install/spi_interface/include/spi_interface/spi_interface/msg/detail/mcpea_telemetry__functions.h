// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from spi_interface:msg/McpeaTelemetry.idl
// generated code does not contain a copyright notice

#ifndef SPI_INTERFACE__MSG__DETAIL__MCPEA_TELEMETRY__FUNCTIONS_H_
#define SPI_INTERFACE__MSG__DETAIL__MCPEA_TELEMETRY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "spi_interface/msg/rosidl_generator_c__visibility_control.h"

#include "spi_interface/msg/detail/mcpea_telemetry__struct.h"

/// Initialize msg/McpeaTelemetry message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * spi_interface__msg__McpeaTelemetry
 * )) before or use
 * spi_interface__msg__McpeaTelemetry__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
bool
spi_interface__msg__McpeaTelemetry__init(spi_interface__msg__McpeaTelemetry * msg);

/// Finalize msg/McpeaTelemetry message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
void
spi_interface__msg__McpeaTelemetry__fini(spi_interface__msg__McpeaTelemetry * msg);

/// Create msg/McpeaTelemetry message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * spi_interface__msg__McpeaTelemetry__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
spi_interface__msg__McpeaTelemetry *
spi_interface__msg__McpeaTelemetry__create();

/// Destroy msg/McpeaTelemetry message.
/**
 * It calls
 * spi_interface__msg__McpeaTelemetry__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
void
spi_interface__msg__McpeaTelemetry__destroy(spi_interface__msg__McpeaTelemetry * msg);

/// Check for msg/McpeaTelemetry message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
bool
spi_interface__msg__McpeaTelemetry__are_equal(const spi_interface__msg__McpeaTelemetry * lhs, const spi_interface__msg__McpeaTelemetry * rhs);

/// Copy a msg/McpeaTelemetry message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
bool
spi_interface__msg__McpeaTelemetry__copy(
  const spi_interface__msg__McpeaTelemetry * input,
  spi_interface__msg__McpeaTelemetry * output);

/// Initialize array of msg/McpeaTelemetry messages.
/**
 * It allocates the memory for the number of elements and calls
 * spi_interface__msg__McpeaTelemetry__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
bool
spi_interface__msg__McpeaTelemetry__Sequence__init(spi_interface__msg__McpeaTelemetry__Sequence * array, size_t size);

/// Finalize array of msg/McpeaTelemetry messages.
/**
 * It calls
 * spi_interface__msg__McpeaTelemetry__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
void
spi_interface__msg__McpeaTelemetry__Sequence__fini(spi_interface__msg__McpeaTelemetry__Sequence * array);

/// Create array of msg/McpeaTelemetry messages.
/**
 * It allocates the memory for the array and calls
 * spi_interface__msg__McpeaTelemetry__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
spi_interface__msg__McpeaTelemetry__Sequence *
spi_interface__msg__McpeaTelemetry__Sequence__create(size_t size);

/// Destroy array of msg/McpeaTelemetry messages.
/**
 * It calls
 * spi_interface__msg__McpeaTelemetry__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
void
spi_interface__msg__McpeaTelemetry__Sequence__destroy(spi_interface__msg__McpeaTelemetry__Sequence * array);

/// Check for msg/McpeaTelemetry message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
bool
spi_interface__msg__McpeaTelemetry__Sequence__are_equal(const spi_interface__msg__McpeaTelemetry__Sequence * lhs, const spi_interface__msg__McpeaTelemetry__Sequence * rhs);

/// Copy an array of msg/McpeaTelemetry messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
bool
spi_interface__msg__McpeaTelemetry__Sequence__copy(
  const spi_interface__msg__McpeaTelemetry__Sequence * input,
  spi_interface__msg__McpeaTelemetry__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SPI_INTERFACE__MSG__DETAIL__MCPEA_TELEMETRY__FUNCTIONS_H_
