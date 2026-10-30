#!/usr/bin/python3
'''
Adam Welker     Utah Robotics Center        Oct. 2026


regulator.py: Mostly a test program. Regulates the leg to 0 joint angle.
'''
import rclpy
from rclpy.node import Node

from spi_interface.msg import McpeaCommand
from spi_interface.msg import McpeaTelemetry
from std_srvs.srv import Trigger

import numpy as np
import actuator_command.actuator_command_params as param



class Regulator(Node):

    def __init__(self):
        '''
        Class constructor. Makes the node and internal variables
        '''

        super().__init__('Regulator_Node')

        self._command_publisher = self.create_publisher(McpeaCommand,'actuator_command',2)
        self._enable_client = self.create_client(Trigger,'actuator_enable')
        self._disable_client = self.create_client(Trigger,'actuator_disable')


        self._timer = self.create_timer(1/500,self.publish_callback)

        # Publish a message to enable the motor
        self.get_logger().warn('Enabling Motor!')

        result = False
        trigger_request = Trigger.Request()

        i = 0
        while(not result) and (i < 1000):
            response = self._enable_client.call_async(trigger_request)
            rclpy.spin_until_future_complete(self, response)

            if response.result().success == True:

                result = True
                self.get_logger().info("Motor Enabled!")
                break

            else:

                self.get_logger().warn('Could not enable motor!')

            i += 1

            if i == 1000:

                self.get_logger().error('Regulator node was not able to enable!')



    def __del__(self):

        # Send a message to disable the actuator

        result = False

        trigger_request = Trigger.Request()
        

        i = 0
        while(not result) and (i < 1000):
            response = self._disable_client.call_async(trigger_request)
            rclpy.spin_until_future_complete(self, response)

            if response.result().success == True:

                result = True
                self.get_logger().info("Regulator node shutting down. Motor Disabled!")

            else:

                self.get_logger().warn('Could not disable motor!')

            i += 1

            if i == 1000:

                self.get_logger().error('Regulator node was not able to disable the motor before shutdown!')



    def publish_callback(self):

        command_msg = McpeaCommand()
        command_msg.control_mode = param.position_control
        command_msg.current_limit = param.std_current_limit
        command_msg.torque_limit = param.std_torque_limit
        command_msg.data_1 = 0. # setpoint 
        command_msg.data_2 = param.std_kp
        command_msg.data_4 = param.std_kd

        self._command_publisher.publish(command_msg)


def main(args=None):

    rclpy.init(args=args) # start rospy

    regulating_node = Regulator() # make the node

    rclpy.spin(regulating_node)

    regulating_node.destroy_node() #when we're done, destroy everything
    rclpy.shutdown()


if __name__ == '__main__':

    main()