#!/usr/bin/python3
'''
Adam Welker     Utah Robotics Center        Oct. 2026


regulator.py: Mostly a test program. Sends blank commands through
'''
import rclpy
from rclpy.node import Node

from spi_interface.msg import McpeaTelemetry
from std_msgs.msg import String

import numpy as np
import actuator_command.everest_core_errors as error_codes



class Error_Reading_Node(Node):

    def __init__(self):
        '''
        Class constructor. Makes the node and internal variables
        '''

        super().__init__('Regulator_Node')

        self._error_subscriber = self.create_subscription(McpeaTelemetry,'actuator_telemetry',self.error_callback,2)
        self._error_publisher = self.create_publisher(String,'actuator_error',2)


    def error_callback(self,msg:McpeaTelemetry):

        error_code = int(msg.error_code)

        error_message = String()

        error_message.data = error_codes.decode_error(error_code)

        self._error_publisher.publish(error_message)

        


def main(args=None):

    rclpy.init(args=args) # start rospy

    error_node = Error_Reading_Node() # make the node

    rclpy.spin(error_node)

    error_node.destroy_node() #when we're done, destroy everything
    rclpy.shutdown()


if __name__ == '__main__':

    main()