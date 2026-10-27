// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from spi_interface:msg/McpeaTelemetry.idl
// generated code does not contain a copyright notice
#include "spi_interface/msg/detail/mcpea_telemetry__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
spi_interface__msg__McpeaTelemetry__init(spi_interface__msg__McpeaTelemetry * msg)
{
  if (!msg) {
    return false;
  }
  // accel_1
  // accel_2
  // accel_3
  // motor_abs_velocity
  // motor_abs_position
  // ing_bus_voltage
  // power_stage_temp
  // motor_inc_position
  // motor_inc_velocity
  // joint_position
  // joint_velocity
  // des_current
  // act_current
  // des_torque
  // control_effort
  // boom_angle
  // error_code
  return true;
}

void
spi_interface__msg__McpeaTelemetry__fini(spi_interface__msg__McpeaTelemetry * msg)
{
  if (!msg) {
    return;
  }
  // accel_1
  // accel_2
  // accel_3
  // motor_abs_velocity
  // motor_abs_position
  // ing_bus_voltage
  // power_stage_temp
  // motor_inc_position
  // motor_inc_velocity
  // joint_position
  // joint_velocity
  // des_current
  // act_current
  // des_torque
  // control_effort
  // boom_angle
  // error_code
}

bool
spi_interface__msg__McpeaTelemetry__are_equal(const spi_interface__msg__McpeaTelemetry * lhs, const spi_interface__msg__McpeaTelemetry * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accel_1
  if (lhs->accel_1 != rhs->accel_1) {
    return false;
  }
  // accel_2
  if (lhs->accel_2 != rhs->accel_2) {
    return false;
  }
  // accel_3
  if (lhs->accel_3 != rhs->accel_3) {
    return false;
  }
  // motor_abs_velocity
  if (lhs->motor_abs_velocity != rhs->motor_abs_velocity) {
    return false;
  }
  // motor_abs_position
  if (lhs->motor_abs_position != rhs->motor_abs_position) {
    return false;
  }
  // ing_bus_voltage
  if (lhs->ing_bus_voltage != rhs->ing_bus_voltage) {
    return false;
  }
  // power_stage_temp
  if (lhs->power_stage_temp != rhs->power_stage_temp) {
    return false;
  }
  // motor_inc_position
  if (lhs->motor_inc_position != rhs->motor_inc_position) {
    return false;
  }
  // motor_inc_velocity
  if (lhs->motor_inc_velocity != rhs->motor_inc_velocity) {
    return false;
  }
  // joint_position
  if (lhs->joint_position != rhs->joint_position) {
    return false;
  }
  // joint_velocity
  if (lhs->joint_velocity != rhs->joint_velocity) {
    return false;
  }
  // des_current
  if (lhs->des_current != rhs->des_current) {
    return false;
  }
  // act_current
  if (lhs->act_current != rhs->act_current) {
    return false;
  }
  // des_torque
  if (lhs->des_torque != rhs->des_torque) {
    return false;
  }
  // control_effort
  if (lhs->control_effort != rhs->control_effort) {
    return false;
  }
  // boom_angle
  if (lhs->boom_angle != rhs->boom_angle) {
    return false;
  }
  // error_code
  if (lhs->error_code != rhs->error_code) {
    return false;
  }
  return true;
}

bool
spi_interface__msg__McpeaTelemetry__copy(
  const spi_interface__msg__McpeaTelemetry * input,
  spi_interface__msg__McpeaTelemetry * output)
{
  if (!input || !output) {
    return false;
  }
  // accel_1
  output->accel_1 = input->accel_1;
  // accel_2
  output->accel_2 = input->accel_2;
  // accel_3
  output->accel_3 = input->accel_3;
  // motor_abs_velocity
  output->motor_abs_velocity = input->motor_abs_velocity;
  // motor_abs_position
  output->motor_abs_position = input->motor_abs_position;
  // ing_bus_voltage
  output->ing_bus_voltage = input->ing_bus_voltage;
  // power_stage_temp
  output->power_stage_temp = input->power_stage_temp;
  // motor_inc_position
  output->motor_inc_position = input->motor_inc_position;
  // motor_inc_velocity
  output->motor_inc_velocity = input->motor_inc_velocity;
  // joint_position
  output->joint_position = input->joint_position;
  // joint_velocity
  output->joint_velocity = input->joint_velocity;
  // des_current
  output->des_current = input->des_current;
  // act_current
  output->act_current = input->act_current;
  // des_torque
  output->des_torque = input->des_torque;
  // control_effort
  output->control_effort = input->control_effort;
  // boom_angle
  output->boom_angle = input->boom_angle;
  // error_code
  output->error_code = input->error_code;
  return true;
}

spi_interface__msg__McpeaTelemetry *
spi_interface__msg__McpeaTelemetry__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spi_interface__msg__McpeaTelemetry * msg = (spi_interface__msg__McpeaTelemetry *)allocator.allocate(sizeof(spi_interface__msg__McpeaTelemetry), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(spi_interface__msg__McpeaTelemetry));
  bool success = spi_interface__msg__McpeaTelemetry__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
spi_interface__msg__McpeaTelemetry__destroy(spi_interface__msg__McpeaTelemetry * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    spi_interface__msg__McpeaTelemetry__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
spi_interface__msg__McpeaTelemetry__Sequence__init(spi_interface__msg__McpeaTelemetry__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spi_interface__msg__McpeaTelemetry * data = NULL;

  if (size) {
    data = (spi_interface__msg__McpeaTelemetry *)allocator.zero_allocate(size, sizeof(spi_interface__msg__McpeaTelemetry), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = spi_interface__msg__McpeaTelemetry__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        spi_interface__msg__McpeaTelemetry__fini(&data[i - 1]);
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
spi_interface__msg__McpeaTelemetry__Sequence__fini(spi_interface__msg__McpeaTelemetry__Sequence * array)
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
      spi_interface__msg__McpeaTelemetry__fini(&array->data[i]);
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

spi_interface__msg__McpeaTelemetry__Sequence *
spi_interface__msg__McpeaTelemetry__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  spi_interface__msg__McpeaTelemetry__Sequence * array = (spi_interface__msg__McpeaTelemetry__Sequence *)allocator.allocate(sizeof(spi_interface__msg__McpeaTelemetry__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = spi_interface__msg__McpeaTelemetry__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
spi_interface__msg__McpeaTelemetry__Sequence__destroy(spi_interface__msg__McpeaTelemetry__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    spi_interface__msg__McpeaTelemetry__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
spi_interface__msg__McpeaTelemetry__Sequence__are_equal(const spi_interface__msg__McpeaTelemetry__Sequence * lhs, const spi_interface__msg__McpeaTelemetry__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!spi_interface__msg__McpeaTelemetry__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
spi_interface__msg__McpeaTelemetry__Sequence__copy(
  const spi_interface__msg__McpeaTelemetry__Sequence * input,
  spi_interface__msg__McpeaTelemetry__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(spi_interface__msg__McpeaTelemetry);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    spi_interface__msg__McpeaTelemetry * data =
      (spi_interface__msg__McpeaTelemetry *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!spi_interface__msg__McpeaTelemetry__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          spi_interface__msg__McpeaTelemetry__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!spi_interface__msg__McpeaTelemetry__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
