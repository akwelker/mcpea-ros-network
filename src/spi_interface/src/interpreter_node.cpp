/**
 * @file interpreter_node.cpp
 * @brief This file is a wrapper for the interpreter class
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

#include "interpreter.h"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Interpreter>());
  rclcpp::shutdown();
  return 0;
}
