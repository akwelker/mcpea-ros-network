# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_actuator_command_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED actuator_command_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(actuator_command_FOUND FALSE)
  elseif(NOT actuator_command_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(actuator_command_FOUND FALSE)
  endif()
  return()
endif()
set(_actuator_command_CONFIG_INCLUDED TRUE)

# output package information
if(NOT actuator_command_FIND_QUIETLY)
  message(STATUS "Found actuator_command: 0.0.0 (${actuator_command_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'actuator_command' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${actuator_command_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(actuator_command_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${actuator_command_DIR}/${_extra}")
endforeach()
