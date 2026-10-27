// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from spi_interface:msg/McpeaCommand.idl
// generated code does not contain a copyright notice

#ifndef SPI_INTERFACE__MSG__DETAIL__MCPEA_COMMAND__FUNCTIONS_H_
#define SPI_INTERFACE__MSG__DETAIL__MCPEA_COMMAND__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "spi_interface/msg/rosidl_generator_c__visibility_control.h"

#include "spi_interface/msg/detail/mcpea_command__struct.h"

/// Initialize msg/McpeaCommand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * spi_interface__msg__McpeaCommand
 * )) before or use
 * spi_interface__msg__McpeaCommand__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
bool
spi_interface__msg__McpeaCommand__init(spi_interface__msg__McpeaCommand * msg);

/// Finalize msg/McpeaCommand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
void
spi_interface__msg__McpeaCommand__fini(spi_interface__msg__McpeaCommand * msg);

/// Create msg/McpeaCommand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * spi_interface__msg__McpeaCommand__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
spi_interface__msg__McpeaCommand *
spi_interface__msg__McpeaCommand__create();

/// Destroy msg/McpeaCommand message.
/**
 * It calls
 * spi_interface__msg__McpeaCommand__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
void
spi_interface__msg__McpeaCommand__destroy(spi_interface__msg__McpeaCommand * msg);

/// Check for msg/McpeaCommand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
bool
spi_interface__msg__McpeaCommand__are_equal(const spi_interface__msg__McpeaCommand * lhs, const spi_interface__msg__McpeaCommand * rhs);

/// Copy a msg/McpeaCommand message.
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
spi_interface__msg__McpeaCommand__copy(
  const spi_interface__msg__McpeaCommand * input,
  spi_interface__msg__McpeaCommand * output);

/// Initialize array of msg/McpeaCommand messages.
/**
 * It allocates the memory for the number of elements and calls
 * spi_interface__msg__McpeaCommand__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
bool
spi_interface__msg__McpeaCommand__Sequence__init(spi_interface__msg__McpeaCommand__Sequence * array, size_t size);

/// Finalize array of msg/McpeaCommand messages.
/**
 * It calls
 * spi_interface__msg__McpeaCommand__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
void
spi_interface__msg__McpeaCommand__Sequence__fini(spi_interface__msg__McpeaCommand__Sequence * array);

/// Create array of msg/McpeaCommand messages.
/**
 * It allocates the memory for the array and calls
 * spi_interface__msg__McpeaCommand__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
spi_interface__msg__McpeaCommand__Sequence *
spi_interface__msg__McpeaCommand__Sequence__create(size_t size);

/// Destroy array of msg/McpeaCommand messages.
/**
 * It calls
 * spi_interface__msg__McpeaCommand__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
void
spi_interface__msg__McpeaCommand__Sequence__destroy(spi_interface__msg__McpeaCommand__Sequence * array);

/// Check for msg/McpeaCommand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_spi_interface
bool
spi_interface__msg__McpeaCommand__Sequence__are_equal(const spi_interface__msg__McpeaCommand__Sequence * lhs, const spi_interface__msg__McpeaCommand__Sequence * rhs);

/// Copy an array of msg/McpeaCommand messages.
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
spi_interface__msg__McpeaCommand__Sequence__copy(
  const spi_interface__msg__McpeaCommand__Sequence * input,
  spi_interface__msg__McpeaCommand__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SPI_INTERFACE__MSG__DETAIL__MCPEA_COMMAND__FUNCTIONS_H_
