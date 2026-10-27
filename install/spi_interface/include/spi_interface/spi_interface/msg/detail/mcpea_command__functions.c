// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from spi_interface:msg/McpeaCommand.idl
// generated code does not contain a copyright notice
#include "spi_interface/msg/detail/mcpea_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
spi_interface__msg__McpeaCommand__init(spi_interface__msg__McpeaCommand * msg)
{
  if (!msg) {
    return false;
  }
  // torque_limit
  // motor_state_cmd
  // current_limit
  // feedforward_torque
  // control_mode
  // data_1
  // data_2
  // data_3
  // data_4
  // data_5
  // dynamic_comp_gain
  // dynamic_comp_on
  return true;
}

void
spi_interface__msg__McpeaCommand__fini(spi_interface__msg__McpeaCommand * msg)
{
  if (!msg) {
    return;
  }
  // torque_limit
  // motor_state_cmd
  // current_limit
  // feedforward_torque
  // control_mode
  // data_1
  // data_2
  // data_3
  // data_4
  // data_5
  // dynamic_comp_gain
  // dynamic_comp_on
}

bool
spi_interface__msg__McpeaCommand__are_equal(const spi_interface__msg__McpeaCommand * lhs, const spi_interface__msg__McpeaCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // torque_limit
  if (lhs->torque_limit != rhs->torque_limit) {
    return false;
  }
  // motor_state_cmd
  if (lhs->motor_state_cmd != rhs->motor_state_cmd) {
    return false;
  }
  // current_limit
  if (lhs->current_limit != rhs->current_limit) {
    return false;
  }
  // feedforward_torque
  if (lhs->feedforward_torque != rhs->feedforward_torque) {
    return false;
  }
  // control_mode
  if (lhs->control_mode != rhs->control_mode) {
    return false;
  }
  // data_1
  if (lhs->data_1 != rhs->data_1) {
    return false;
  }
  // data_2
  if (lhs->data_2 != rhs->data_2) {
    return false;
  }
  // data_3
  if (lhs->data_3 != rhs->data_3) {
    return false;
  }
  // data_4
  if (lhs->data_4 != rhs->data_4) {
    return false;
  }
  // data_5
  if (lhs->data_5 != rhs->data_5) {
    return false;
  }
  // dynamic_comp_gain
  if (lhs->dynamic_comp_gain != rhs->dynamic_comp_gain) {
    return false;
  }
  // dynamic_comp_on
  if (lhs->dynamic_comp_on != rhs->dynamic_comp_on) {
    return false;
  }
  return true;
}

bool
spi_interface__msg__McpeaCommand__copy(
  const spi_interface__msg__McpeaCommand * input,
  spi_interface__msg__McpeaCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // torque_limit
  output->torque_limit = input->torque_limit;
  // motor_state_cmd
  output->motor_state_cmd = input->motor_state_cmd;
  // current_limit
  output->current_limit = input->current_limit;
  // feedforward_torque
  output->feedforward_torque = input->feedforward_torque;
  // control_mode
  output->control_mode = input->control_mode;
  // data_1
  output->data_1 = input->data_1;
  // data_2
  output->data_2 = input->data_2;
  // data_3
  output->data_3 = input->data_3;
  // data_4
  output->data_4 = input->data_4;
  // data_5
  output->data_5 = input->data_5;
  // dynamic_comp_gain
  output->dynamic_comp_gain = input->dynamic_comp_gain;
  // dynamic_comp_on
  output->dynamic_comp_on = input->dynamic_comp_on;
  return true;
}

spi_interface__msg__McpeaCommand *
spi_interface__msg__McpeaCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spi_interface__msg__McpeaCommand * msg = (spi_interface__msg__McpeaCommand *)allocator.allocate(sizeof(spi_interface__msg__McpeaCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(spi_interface__msg__McpeaCommand));
  bool success = spi_interface__msg__McpeaCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
spi_interface__msg__McpeaCommand__destroy(spi_interface__msg__McpeaCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    spi_interface__msg__McpeaCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
spi_interface__msg__McpeaCommand__Sequence__init(spi_interface__msg__McpeaCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spi_interface__msg__McpeaCommand * data = NULL;

  if (size) {
    data = (spi_interface__msg__McpeaCommand *)allocator.zero_allocate(size, sizeof(spi_interface__msg__McpeaCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = spi_interface__msg__McpeaCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        spi_interface__msg__McpeaCommand__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
spi_interface__msg__McpeaCommand__Sequence__fini(spi_interface__msg__McpeaCommand__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      spi_interface__msg__McpeaCommand__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

spi_interface__msg__McpeaCommand__Sequence *
spi_interface__msg__McpeaCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spi_interface__msg__McpeaCommand__Sequence * array = (spi_interface__msg__McpeaCommand__Sequence *)allocator.allocate(sizeof(spi_interface__msg__McpeaCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = spi_interface__msg__McpeaCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
spi_interface__msg__McpeaCommand__Sequence__destroy(spi_interface__msg__McpeaCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    spi_interface__msg__McpeaCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
spi_interface__msg__McpeaCommand__Sequence__are_equal(const spi_interface__msg__McpeaCommand__Sequence * lhs, const spi_interface__msg__McpeaCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!spi_interface__msg__McpeaCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
spi_interface__msg__McpeaCommand__Sequence__copy(
  const spi_interface__msg__McpeaCommand__Sequence * input,
  spi_interface__msg__McpeaCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(spi_interface__msg__McpeaCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    spi_interface__msg__McpeaCommand * data =
      (spi_interface__msg__McpeaCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!spi_interface__msg__McpeaCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          spi_interface__msg__McpeaCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!spi_interface__msg__McpeaCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
