// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from action_demo:action/Fibonacci.idl
// generated code does not contain a copyright notice
#include "action_demo/action/detail/fibonacci__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
action_demo__action__Fibonacci_Goal__init(action_demo__action__Fibonacci_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // order
  return true;
}

void
action_demo__action__Fibonacci_Goal__fini(action_demo__action__Fibonacci_Goal * msg)
{
  if (!msg) {
    return;
  }
  // order
}

bool
action_demo__action__Fibonacci_Goal__are_equal(const action_demo__action__Fibonacci_Goal * lhs, const action_demo__action__Fibonacci_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // order
  if (lhs->order != rhs->order) {
    return false;
  }
  return true;
}

bool
action_demo__action__Fibonacci_Goal__copy(
  const action_demo__action__Fibonacci_Goal * input,
  action_demo__action__Fibonacci_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // order
  output->order = input->order;
  return true;
}

action_demo__action__Fibonacci_Goal *
action_demo__action__Fibonacci_Goal__create()
{
  action_demo__action__Fibonacci_Goal * msg = (action_demo__action__Fibonacci_Goal *)malloc(sizeof(action_demo__action__Fibonacci_Goal));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_demo__action__Fibonacci_Goal));
  bool success = action_demo__action__Fibonacci_Goal__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
action_demo__action__Fibonacci_Goal__destroy(action_demo__action__Fibonacci_Goal * msg)
{
  if (msg) {
    action_demo__action__Fibonacci_Goal__fini(msg);
  }
  free(msg);
}


bool
action_demo__action__Fibonacci_Goal__Sequence__init(action_demo__action__Fibonacci_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  action_demo__action__Fibonacci_Goal * data = NULL;
  if (size) {
    data = (action_demo__action__Fibonacci_Goal *)calloc(size, sizeof(action_demo__action__Fibonacci_Goal));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_demo__action__Fibonacci_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_demo__action__Fibonacci_Goal__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_demo__action__Fibonacci_Goal__Sequence__fini(action_demo__action__Fibonacci_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_demo__action__Fibonacci_Goal__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_demo__action__Fibonacci_Goal__Sequence *
action_demo__action__Fibonacci_Goal__Sequence__create(size_t size)
{
  action_demo__action__Fibonacci_Goal__Sequence * array = (action_demo__action__Fibonacci_Goal__Sequence *)malloc(sizeof(action_demo__action__Fibonacci_Goal__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = action_demo__action__Fibonacci_Goal__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
action_demo__action__Fibonacci_Goal__Sequence__destroy(action_demo__action__Fibonacci_Goal__Sequence * array)
{
  if (array) {
    action_demo__action__Fibonacci_Goal__Sequence__fini(array);
  }
  free(array);
}

bool
action_demo__action__Fibonacci_Goal__Sequence__are_equal(const action_demo__action__Fibonacci_Goal__Sequence * lhs, const action_demo__action__Fibonacci_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_demo__action__Fibonacci_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_demo__action__Fibonacci_Goal__Sequence__copy(
  const action_demo__action__Fibonacci_Goal__Sequence * input,
  action_demo__action__Fibonacci_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_demo__action__Fibonacci_Goal);
    action_demo__action__Fibonacci_Goal * data =
      (action_demo__action__Fibonacci_Goal *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_demo__action__Fibonacci_Goal__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          action_demo__action__Fibonacci_Goal__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_demo__action__Fibonacci_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `sequence`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
action_demo__action__Fibonacci_Result__init(action_demo__action__Fibonacci_Result * msg)
{
  if (!msg) {
    return false;
  }
  // sequence
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->sequence, 0)) {
    action_demo__action__Fibonacci_Result__fini(msg);
    return false;
  }
  return true;
}

void
action_demo__action__Fibonacci_Result__fini(action_demo__action__Fibonacci_Result * msg)
{
  if (!msg) {
    return;
  }
  // sequence
  rosidl_runtime_c__int32__Sequence__fini(&msg->sequence);
}

bool
action_demo__action__Fibonacci_Result__are_equal(const action_demo__action__Fibonacci_Result * lhs, const action_demo__action__Fibonacci_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sequence
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->sequence), &(rhs->sequence)))
  {
    return false;
  }
  return true;
}

bool
action_demo__action__Fibonacci_Result__copy(
  const action_demo__action__Fibonacci_Result * input,
  action_demo__action__Fibonacci_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // sequence
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->sequence), &(output->sequence)))
  {
    return false;
  }
  return true;
}

action_demo__action__Fibonacci_Result *
action_demo__action__Fibonacci_Result__create()
{
  action_demo__action__Fibonacci_Result * msg = (action_demo__action__Fibonacci_Result *)malloc(sizeof(action_demo__action__Fibonacci_Result));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_demo__action__Fibonacci_Result));
  bool success = action_demo__action__Fibonacci_Result__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
action_demo__action__Fibonacci_Result__destroy(action_demo__action__Fibonacci_Result * msg)
{
  if (msg) {
    action_demo__action__Fibonacci_Result__fini(msg);
  }
  free(msg);
}


bool
action_demo__action__Fibonacci_Result__Sequence__init(action_demo__action__Fibonacci_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  action_demo__action__Fibonacci_Result * data = NULL;
  if (size) {
    data = (action_demo__action__Fibonacci_Result *)calloc(size, sizeof(action_demo__action__Fibonacci_Result));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_demo__action__Fibonacci_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_demo__action__Fibonacci_Result__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_demo__action__Fibonacci_Result__Sequence__fini(action_demo__action__Fibonacci_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_demo__action__Fibonacci_Result__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_demo__action__Fibonacci_Result__Sequence *
action_demo__action__Fibonacci_Result__Sequence__create(size_t size)
{
  action_demo__action__Fibonacci_Result__Sequence * array = (action_demo__action__Fibonacci_Result__Sequence *)malloc(sizeof(action_demo__action__Fibonacci_Result__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = action_demo__action__Fibonacci_Result__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
action_demo__action__Fibonacci_Result__Sequence__destroy(action_demo__action__Fibonacci_Result__Sequence * array)
{
  if (array) {
    action_demo__action__Fibonacci_Result__Sequence__fini(array);
  }
  free(array);
}

bool
action_demo__action__Fibonacci_Result__Sequence__are_equal(const action_demo__action__Fibonacci_Result__Sequence * lhs, const action_demo__action__Fibonacci_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_demo__action__Fibonacci_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_demo__action__Fibonacci_Result__Sequence__copy(
  const action_demo__action__Fibonacci_Result__Sequence * input,
  action_demo__action__Fibonacci_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_demo__action__Fibonacci_Result);
    action_demo__action__Fibonacci_Result * data =
      (action_demo__action__Fibonacci_Result *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_demo__action__Fibonacci_Result__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          action_demo__action__Fibonacci_Result__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_demo__action__Fibonacci_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `partial_sequence`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
action_demo__action__Fibonacci_Feedback__init(action_demo__action__Fibonacci_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // partial_sequence
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->partial_sequence, 0)) {
    action_demo__action__Fibonacci_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
action_demo__action__Fibonacci_Feedback__fini(action_demo__action__Fibonacci_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // partial_sequence
  rosidl_runtime_c__int32__Sequence__fini(&msg->partial_sequence);
}

bool
action_demo__action__Fibonacci_Feedback__are_equal(const action_demo__action__Fibonacci_Feedback * lhs, const action_demo__action__Fibonacci_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // partial_sequence
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->partial_sequence), &(rhs->partial_sequence)))
  {
    return false;
  }
  return true;
}

bool
action_demo__action__Fibonacci_Feedback__copy(
  const action_demo__action__Fibonacci_Feedback * input,
  action_demo__action__Fibonacci_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // partial_sequence
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->partial_sequence), &(output->partial_sequence)))
  {
    return false;
  }
  return true;
}

action_demo__action__Fibonacci_Feedback *
action_demo__action__Fibonacci_Feedback__create()
{
  action_demo__action__Fibonacci_Feedback * msg = (action_demo__action__Fibonacci_Feedback *)malloc(sizeof(action_demo__action__Fibonacci_Feedback));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_demo__action__Fibonacci_Feedback));
  bool success = action_demo__action__Fibonacci_Feedback__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
action_demo__action__Fibonacci_Feedback__destroy(action_demo__action__Fibonacci_Feedback * msg)
{
  if (msg) {
    action_demo__action__Fibonacci_Feedback__fini(msg);
  }
  free(msg);
}


bool
action_demo__action__Fibonacci_Feedback__Sequence__init(action_demo__action__Fibonacci_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  action_demo__action__Fibonacci_Feedback * data = NULL;
  if (size) {
    data = (action_demo__action__Fibonacci_Feedback *)calloc(size, sizeof(action_demo__action__Fibonacci_Feedback));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_demo__action__Fibonacci_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_demo__action__Fibonacci_Feedback__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_demo__action__Fibonacci_Feedback__Sequence__fini(action_demo__action__Fibonacci_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_demo__action__Fibonacci_Feedback__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_demo__action__Fibonacci_Feedback__Sequence *
action_demo__action__Fibonacci_Feedback__Sequence__create(size_t size)
{
  action_demo__action__Fibonacci_Feedback__Sequence * array = (action_demo__action__Fibonacci_Feedback__Sequence *)malloc(sizeof(action_demo__action__Fibonacci_Feedback__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = action_demo__action__Fibonacci_Feedback__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
action_demo__action__Fibonacci_Feedback__Sequence__destroy(action_demo__action__Fibonacci_Feedback__Sequence * array)
{
  if (array) {
    action_demo__action__Fibonacci_Feedback__Sequence__fini(array);
  }
  free(array);
}

bool
action_demo__action__Fibonacci_Feedback__Sequence__are_equal(const action_demo__action__Fibonacci_Feedback__Sequence * lhs, const action_demo__action__Fibonacci_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_demo__action__Fibonacci_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_demo__action__Fibonacci_Feedback__Sequence__copy(
  const action_demo__action__Fibonacci_Feedback__Sequence * input,
  action_demo__action__Fibonacci_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_demo__action__Fibonacci_Feedback);
    action_demo__action__Fibonacci_Feedback * data =
      (action_demo__action__Fibonacci_Feedback *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_demo__action__Fibonacci_Feedback__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          action_demo__action__Fibonacci_Feedback__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_demo__action__Fibonacci_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "action_demo/action/detail/fibonacci__functions.h"

bool
action_demo__action__Fibonacci_SendGoal_Request__init(action_demo__action__Fibonacci_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    action_demo__action__Fibonacci_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!action_demo__action__Fibonacci_Goal__init(&msg->goal)) {
    action_demo__action__Fibonacci_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
action_demo__action__Fibonacci_SendGoal_Request__fini(action_demo__action__Fibonacci_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  action_demo__action__Fibonacci_Goal__fini(&msg->goal);
}

bool
action_demo__action__Fibonacci_SendGoal_Request__are_equal(const action_demo__action__Fibonacci_SendGoal_Request * lhs, const action_demo__action__Fibonacci_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!action_demo__action__Fibonacci_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
action_demo__action__Fibonacci_SendGoal_Request__copy(
  const action_demo__action__Fibonacci_SendGoal_Request * input,
  action_demo__action__Fibonacci_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!action_demo__action__Fibonacci_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

action_demo__action__Fibonacci_SendGoal_Request *
action_demo__action__Fibonacci_SendGoal_Request__create()
{
  action_demo__action__Fibonacci_SendGoal_Request * msg = (action_demo__action__Fibonacci_SendGoal_Request *)malloc(sizeof(action_demo__action__Fibonacci_SendGoal_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_demo__action__Fibonacci_SendGoal_Request));
  bool success = action_demo__action__Fibonacci_SendGoal_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
action_demo__action__Fibonacci_SendGoal_Request__destroy(action_demo__action__Fibonacci_SendGoal_Request * msg)
{
  if (msg) {
    action_demo__action__Fibonacci_SendGoal_Request__fini(msg);
  }
  free(msg);
}


bool
action_demo__action__Fibonacci_SendGoal_Request__Sequence__init(action_demo__action__Fibonacci_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  action_demo__action__Fibonacci_SendGoal_Request * data = NULL;
  if (size) {
    data = (action_demo__action__Fibonacci_SendGoal_Request *)calloc(size, sizeof(action_demo__action__Fibonacci_SendGoal_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_demo__action__Fibonacci_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_demo__action__Fibonacci_SendGoal_Request__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_demo__action__Fibonacci_SendGoal_Request__Sequence__fini(action_demo__action__Fibonacci_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_demo__action__Fibonacci_SendGoal_Request__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_demo__action__Fibonacci_SendGoal_Request__Sequence *
action_demo__action__Fibonacci_SendGoal_Request__Sequence__create(size_t size)
{
  action_demo__action__Fibonacci_SendGoal_Request__Sequence * array = (action_demo__action__Fibonacci_SendGoal_Request__Sequence *)malloc(sizeof(action_demo__action__Fibonacci_SendGoal_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = action_demo__action__Fibonacci_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
action_demo__action__Fibonacci_SendGoal_Request__Sequence__destroy(action_demo__action__Fibonacci_SendGoal_Request__Sequence * array)
{
  if (array) {
    action_demo__action__Fibonacci_SendGoal_Request__Sequence__fini(array);
  }
  free(array);
}

bool
action_demo__action__Fibonacci_SendGoal_Request__Sequence__are_equal(const action_demo__action__Fibonacci_SendGoal_Request__Sequence * lhs, const action_demo__action__Fibonacci_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_demo__action__Fibonacci_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_demo__action__Fibonacci_SendGoal_Request__Sequence__copy(
  const action_demo__action__Fibonacci_SendGoal_Request__Sequence * input,
  action_demo__action__Fibonacci_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_demo__action__Fibonacci_SendGoal_Request);
    action_demo__action__Fibonacci_SendGoal_Request * data =
      (action_demo__action__Fibonacci_SendGoal_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_demo__action__Fibonacci_SendGoal_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          action_demo__action__Fibonacci_SendGoal_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_demo__action__Fibonacci_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
action_demo__action__Fibonacci_SendGoal_Response__init(action_demo__action__Fibonacci_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    action_demo__action__Fibonacci_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
action_demo__action__Fibonacci_SendGoal_Response__fini(action_demo__action__Fibonacci_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
action_demo__action__Fibonacci_SendGoal_Response__are_equal(const action_demo__action__Fibonacci_SendGoal_Response * lhs, const action_demo__action__Fibonacci_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
action_demo__action__Fibonacci_SendGoal_Response__copy(
  const action_demo__action__Fibonacci_SendGoal_Response * input,
  action_demo__action__Fibonacci_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

action_demo__action__Fibonacci_SendGoal_Response *
action_demo__action__Fibonacci_SendGoal_Response__create()
{
  action_demo__action__Fibonacci_SendGoal_Response * msg = (action_demo__action__Fibonacci_SendGoal_Response *)malloc(sizeof(action_demo__action__Fibonacci_SendGoal_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_demo__action__Fibonacci_SendGoal_Response));
  bool success = action_demo__action__Fibonacci_SendGoal_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
action_demo__action__Fibonacci_SendGoal_Response__destroy(action_demo__action__Fibonacci_SendGoal_Response * msg)
{
  if (msg) {
    action_demo__action__Fibonacci_SendGoal_Response__fini(msg);
  }
  free(msg);
}


bool
action_demo__action__Fibonacci_SendGoal_Response__Sequence__init(action_demo__action__Fibonacci_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  action_demo__action__Fibonacci_SendGoal_Response * data = NULL;
  if (size) {
    data = (action_demo__action__Fibonacci_SendGoal_Response *)calloc(size, sizeof(action_demo__action__Fibonacci_SendGoal_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_demo__action__Fibonacci_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_demo__action__Fibonacci_SendGoal_Response__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_demo__action__Fibonacci_SendGoal_Response__Sequence__fini(action_demo__action__Fibonacci_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_demo__action__Fibonacci_SendGoal_Response__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_demo__action__Fibonacci_SendGoal_Response__Sequence *
action_demo__action__Fibonacci_SendGoal_Response__Sequence__create(size_t size)
{
  action_demo__action__Fibonacci_SendGoal_Response__Sequence * array = (action_demo__action__Fibonacci_SendGoal_Response__Sequence *)malloc(sizeof(action_demo__action__Fibonacci_SendGoal_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = action_demo__action__Fibonacci_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
action_demo__action__Fibonacci_SendGoal_Response__Sequence__destroy(action_demo__action__Fibonacci_SendGoal_Response__Sequence * array)
{
  if (array) {
    action_demo__action__Fibonacci_SendGoal_Response__Sequence__fini(array);
  }
  free(array);
}

bool
action_demo__action__Fibonacci_SendGoal_Response__Sequence__are_equal(const action_demo__action__Fibonacci_SendGoal_Response__Sequence * lhs, const action_demo__action__Fibonacci_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_demo__action__Fibonacci_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_demo__action__Fibonacci_SendGoal_Response__Sequence__copy(
  const action_demo__action__Fibonacci_SendGoal_Response__Sequence * input,
  action_demo__action__Fibonacci_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_demo__action__Fibonacci_SendGoal_Response);
    action_demo__action__Fibonacci_SendGoal_Response * data =
      (action_demo__action__Fibonacci_SendGoal_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_demo__action__Fibonacci_SendGoal_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          action_demo__action__Fibonacci_SendGoal_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_demo__action__Fibonacci_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
action_demo__action__Fibonacci_GetResult_Request__init(action_demo__action__Fibonacci_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    action_demo__action__Fibonacci_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
action_demo__action__Fibonacci_GetResult_Request__fini(action_demo__action__Fibonacci_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
action_demo__action__Fibonacci_GetResult_Request__are_equal(const action_demo__action__Fibonacci_GetResult_Request * lhs, const action_demo__action__Fibonacci_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
action_demo__action__Fibonacci_GetResult_Request__copy(
  const action_demo__action__Fibonacci_GetResult_Request * input,
  action_demo__action__Fibonacci_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

action_demo__action__Fibonacci_GetResult_Request *
action_demo__action__Fibonacci_GetResult_Request__create()
{
  action_demo__action__Fibonacci_GetResult_Request * msg = (action_demo__action__Fibonacci_GetResult_Request *)malloc(sizeof(action_demo__action__Fibonacci_GetResult_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_demo__action__Fibonacci_GetResult_Request));
  bool success = action_demo__action__Fibonacci_GetResult_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
action_demo__action__Fibonacci_GetResult_Request__destroy(action_demo__action__Fibonacci_GetResult_Request * msg)
{
  if (msg) {
    action_demo__action__Fibonacci_GetResult_Request__fini(msg);
  }
  free(msg);
}


bool
action_demo__action__Fibonacci_GetResult_Request__Sequence__init(action_demo__action__Fibonacci_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  action_demo__action__Fibonacci_GetResult_Request * data = NULL;
  if (size) {
    data = (action_demo__action__Fibonacci_GetResult_Request *)calloc(size, sizeof(action_demo__action__Fibonacci_GetResult_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_demo__action__Fibonacci_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_demo__action__Fibonacci_GetResult_Request__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_demo__action__Fibonacci_GetResult_Request__Sequence__fini(action_demo__action__Fibonacci_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_demo__action__Fibonacci_GetResult_Request__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_demo__action__Fibonacci_GetResult_Request__Sequence *
action_demo__action__Fibonacci_GetResult_Request__Sequence__create(size_t size)
{
  action_demo__action__Fibonacci_GetResult_Request__Sequence * array = (action_demo__action__Fibonacci_GetResult_Request__Sequence *)malloc(sizeof(action_demo__action__Fibonacci_GetResult_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = action_demo__action__Fibonacci_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
action_demo__action__Fibonacci_GetResult_Request__Sequence__destroy(action_demo__action__Fibonacci_GetResult_Request__Sequence * array)
{
  if (array) {
    action_demo__action__Fibonacci_GetResult_Request__Sequence__fini(array);
  }
  free(array);
}

bool
action_demo__action__Fibonacci_GetResult_Request__Sequence__are_equal(const action_demo__action__Fibonacci_GetResult_Request__Sequence * lhs, const action_demo__action__Fibonacci_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_demo__action__Fibonacci_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_demo__action__Fibonacci_GetResult_Request__Sequence__copy(
  const action_demo__action__Fibonacci_GetResult_Request__Sequence * input,
  action_demo__action__Fibonacci_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_demo__action__Fibonacci_GetResult_Request);
    action_demo__action__Fibonacci_GetResult_Request * data =
      (action_demo__action__Fibonacci_GetResult_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_demo__action__Fibonacci_GetResult_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          action_demo__action__Fibonacci_GetResult_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_demo__action__Fibonacci_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "action_demo/action/detail/fibonacci__functions.h"

bool
action_demo__action__Fibonacci_GetResult_Response__init(action_demo__action__Fibonacci_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!action_demo__action__Fibonacci_Result__init(&msg->result)) {
    action_demo__action__Fibonacci_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
action_demo__action__Fibonacci_GetResult_Response__fini(action_demo__action__Fibonacci_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  action_demo__action__Fibonacci_Result__fini(&msg->result);
}

bool
action_demo__action__Fibonacci_GetResult_Response__are_equal(const action_demo__action__Fibonacci_GetResult_Response * lhs, const action_demo__action__Fibonacci_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!action_demo__action__Fibonacci_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
action_demo__action__Fibonacci_GetResult_Response__copy(
  const action_demo__action__Fibonacci_GetResult_Response * input,
  action_demo__action__Fibonacci_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!action_demo__action__Fibonacci_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

action_demo__action__Fibonacci_GetResult_Response *
action_demo__action__Fibonacci_GetResult_Response__create()
{
  action_demo__action__Fibonacci_GetResult_Response * msg = (action_demo__action__Fibonacci_GetResult_Response *)malloc(sizeof(action_demo__action__Fibonacci_GetResult_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_demo__action__Fibonacci_GetResult_Response));
  bool success = action_demo__action__Fibonacci_GetResult_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
action_demo__action__Fibonacci_GetResult_Response__destroy(action_demo__action__Fibonacci_GetResult_Response * msg)
{
  if (msg) {
    action_demo__action__Fibonacci_GetResult_Response__fini(msg);
  }
  free(msg);
}


bool
action_demo__action__Fibonacci_GetResult_Response__Sequence__init(action_demo__action__Fibonacci_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  action_demo__action__Fibonacci_GetResult_Response * data = NULL;
  if (size) {
    data = (action_demo__action__Fibonacci_GetResult_Response *)calloc(size, sizeof(action_demo__action__Fibonacci_GetResult_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_demo__action__Fibonacci_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_demo__action__Fibonacci_GetResult_Response__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_demo__action__Fibonacci_GetResult_Response__Sequence__fini(action_demo__action__Fibonacci_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_demo__action__Fibonacci_GetResult_Response__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_demo__action__Fibonacci_GetResult_Response__Sequence *
action_demo__action__Fibonacci_GetResult_Response__Sequence__create(size_t size)
{
  action_demo__action__Fibonacci_GetResult_Response__Sequence * array = (action_demo__action__Fibonacci_GetResult_Response__Sequence *)malloc(sizeof(action_demo__action__Fibonacci_GetResult_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = action_demo__action__Fibonacci_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
action_demo__action__Fibonacci_GetResult_Response__Sequence__destroy(action_demo__action__Fibonacci_GetResult_Response__Sequence * array)
{
  if (array) {
    action_demo__action__Fibonacci_GetResult_Response__Sequence__fini(array);
  }
  free(array);
}

bool
action_demo__action__Fibonacci_GetResult_Response__Sequence__are_equal(const action_demo__action__Fibonacci_GetResult_Response__Sequence * lhs, const action_demo__action__Fibonacci_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_demo__action__Fibonacci_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_demo__action__Fibonacci_GetResult_Response__Sequence__copy(
  const action_demo__action__Fibonacci_GetResult_Response__Sequence * input,
  action_demo__action__Fibonacci_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_demo__action__Fibonacci_GetResult_Response);
    action_demo__action__Fibonacci_GetResult_Response * data =
      (action_demo__action__Fibonacci_GetResult_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_demo__action__Fibonacci_GetResult_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          action_demo__action__Fibonacci_GetResult_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_demo__action__Fibonacci_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "action_demo/action/detail/fibonacci__functions.h"

bool
action_demo__action__Fibonacci_FeedbackMessage__init(action_demo__action__Fibonacci_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    action_demo__action__Fibonacci_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!action_demo__action__Fibonacci_Feedback__init(&msg->feedback)) {
    action_demo__action__Fibonacci_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
action_demo__action__Fibonacci_FeedbackMessage__fini(action_demo__action__Fibonacci_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  action_demo__action__Fibonacci_Feedback__fini(&msg->feedback);
}

bool
action_demo__action__Fibonacci_FeedbackMessage__are_equal(const action_demo__action__Fibonacci_FeedbackMessage * lhs, const action_demo__action__Fibonacci_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!action_demo__action__Fibonacci_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
action_demo__action__Fibonacci_FeedbackMessage__copy(
  const action_demo__action__Fibonacci_FeedbackMessage * input,
  action_demo__action__Fibonacci_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!action_demo__action__Fibonacci_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

action_demo__action__Fibonacci_FeedbackMessage *
action_demo__action__Fibonacci_FeedbackMessage__create()
{
  action_demo__action__Fibonacci_FeedbackMessage * msg = (action_demo__action__Fibonacci_FeedbackMessage *)malloc(sizeof(action_demo__action__Fibonacci_FeedbackMessage));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_demo__action__Fibonacci_FeedbackMessage));
  bool success = action_demo__action__Fibonacci_FeedbackMessage__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
action_demo__action__Fibonacci_FeedbackMessage__destroy(action_demo__action__Fibonacci_FeedbackMessage * msg)
{
  if (msg) {
    action_demo__action__Fibonacci_FeedbackMessage__fini(msg);
  }
  free(msg);
}


bool
action_demo__action__Fibonacci_FeedbackMessage__Sequence__init(action_demo__action__Fibonacci_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  action_demo__action__Fibonacci_FeedbackMessage * data = NULL;
  if (size) {
    data = (action_demo__action__Fibonacci_FeedbackMessage *)calloc(size, sizeof(action_demo__action__Fibonacci_FeedbackMessage));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_demo__action__Fibonacci_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_demo__action__Fibonacci_FeedbackMessage__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_demo__action__Fibonacci_FeedbackMessage__Sequence__fini(action_demo__action__Fibonacci_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_demo__action__Fibonacci_FeedbackMessage__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_demo__action__Fibonacci_FeedbackMessage__Sequence *
action_demo__action__Fibonacci_FeedbackMessage__Sequence__create(size_t size)
{
  action_demo__action__Fibonacci_FeedbackMessage__Sequence * array = (action_demo__action__Fibonacci_FeedbackMessage__Sequence *)malloc(sizeof(action_demo__action__Fibonacci_FeedbackMessage__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = action_demo__action__Fibonacci_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
action_demo__action__Fibonacci_FeedbackMessage__Sequence__destroy(action_demo__action__Fibonacci_FeedbackMessage__Sequence * array)
{
  if (array) {
    action_demo__action__Fibonacci_FeedbackMessage__Sequence__fini(array);
  }
  free(array);
}

bool
action_demo__action__Fibonacci_FeedbackMessage__Sequence__are_equal(const action_demo__action__Fibonacci_FeedbackMessage__Sequence * lhs, const action_demo__action__Fibonacci_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_demo__action__Fibonacci_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_demo__action__Fibonacci_FeedbackMessage__Sequence__copy(
  const action_demo__action__Fibonacci_FeedbackMessage__Sequence * input,
  action_demo__action__Fibonacci_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_demo__action__Fibonacci_FeedbackMessage);
    action_demo__action__Fibonacci_FeedbackMessage * data =
      (action_demo__action__Fibonacci_FeedbackMessage *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_demo__action__Fibonacci_FeedbackMessage__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          action_demo__action__Fibonacci_FeedbackMessage__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_demo__action__Fibonacci_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
