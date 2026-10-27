cmake_minimum_required(VERSION 3.8)
project(spi_interface)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

message(STATUS "Looking for msg/McpeaTelemetry.msg in ${CMAKE_CURRENT_SOURCE_DIR}/msg")


# find dependencies -- Must match the xml file!
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_srvs REQUIRED)

include_directories(include)

set(msg_files
  "msg/McpeaCommand.msg"
  "msg/McpeaTelemetry.msg"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
)


#Compile the the spi_bridge
ament_export_dependencies(rosidl_default_runtime)


find_library(wiringPi_LIB wiringPi)
if(wiringPi_LIB)
  message(STATUS "Detected WiringPI -- Building spi_bridge")
  add_executable(spi_bridge_node
               src/spi_bridge.cpp
               src/spi_bridge_node.cpp) 
  ament_target_dependencies(spi_bridge_node rclcpp std_msgs std_srvs)
  target_link_libraries(spi_bridge_node ${wiringPi_LIB})
  install(TARGETS
        spi_bridge_node
        DESTINATION lib/${PROJECT_NAME})

else()
  message(WARNING "wiringPi not found: skipping spi_bridge_node (expected on non-Pi machines)")
endif()



# compile interpreter -- build on all systems

add_executable(interpreter_node
               src/interpreter.cpp
               src/interpreter_node.cpp)

ament_target_dependencies(interpreter_node rclcpp std_msgs std_srvs)

rosidl_target_interfaces(interpreter_node
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

install(TARGETS
    interpreter_node
    DESTINATION lib/${PROJECT_NAME})


# Scrap from old solutions
# add_executable(actuator_bridge_node
#                src/actuator_bridge.cpp
#                src/actuator_bridge_node.cpp) 
# ament_target_dependencies(actuator_bridge_node rclcpp std_msgs)
# find_library(wiringPi_LIB wiringPi)
# if(NOT wiringPi_LIB)
#   message(FATAL_ERROR "wiringPi library not found")
# endif()
# target_link_libraries(actuator_bridge_node ${wiringPi_LIB})
# rosidl_target_interfaces(actuator_bridge_node
#   ${PROJECT_NAME} "rosidl_typesupport_cpp")


# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# Install launch files.
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
