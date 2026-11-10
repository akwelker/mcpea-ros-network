#!/usr/bin/python3
'''
Adam Welker     Utah Robotics Center        Oct. 2026


regulator.py: Mostly a test program. Sends blank commands through
'''
import rclpy
from rclpy.node import Node

from std_msgs.msg import Float32
from time import time

import numpy as np
import actuator_command.actuator_command_params as param

AMPLITUDE = 40.
OMEGA = np.pi


class Sleep_Node(Node):

    def __init__(self):
        '''
        Class constructor. Makes the node and internal variables
        '''

        super().__init__('Regulator_Node')

        self._ref_publisher = self.create_publisher(Float32,'reference_signal',2)

        self._timer = self.create_timer(1/500,self.publish_callback)


        self.ref_time = time()

    def publish_callback(self):

        t = time() - self.ref_time

        ref = AMPLITUDE*np.sign(np.sin(OMEGA*t))

        reg_msg = Float32()

        reg_msg.data = ref

        self._ref_publisher.publish(reg_msg)


def main(args=None):

    rclpy.init(args=args) # start rospy

    regulating_node = Sleep_Node() # make the node

    rclpy.spin(regulating_node)

    regulating_node.destroy_node() #when we're done, destroy everything
    rclpy.shutdown()


if __name__ == '__main__':

    main()