/**
 * @file actuator_node.cpp
 * @brief This wrapper file for the actuator bridge class
 * 
 * @author Adam Welker
 * @date Summer 2025
 */
#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include "actuator_bridge.h"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Actuator_Bridge>(25.0));
  rclcpp::shutdown();
  return 0;
}
