#!/usr/bin/python3
'''
Adam Welker     Utah Robotics Center        Oct. 2026


jumping_state_machine.py: A program that runs a state machine used to make
the MC-PEA leg jump.
'''
import rclpy
from rclpy.node import Node

from spi_interface.msg import McpeaCommand
from spi_interface.msg import McpeaTelemetry

import numpy as np
from enum import Enum


class State(Enum):
    INIT = 1
    WAITING = 2
    PRELOADING = 3
    EXTENDING = 4
    AIRBORNE = 5
    LANDING = 6



class jumping_state_machine(Node):

    def __init__(self):
        '''
        Class constructor. Makes the node and internal variables
        '''

        super().__init__('jumping_state_machine')

        self._telemetry_subscriber = self.create_subscription(McpeaTelemetry, 'actuator_telemetry',self.telemetry_callback,2)
        self._command_publisher = self.create_publisher(McpeaCommand,'actuator_command',2)

        # What are the relavent telemetry values
        self.curr_joint_angle = None
        self.curr_joint_velocity = None
        self.curr_motor_torque = None

        # What is the current state machine state
        self.state = State.INIT




    def telemetry_callback(self,msg):

        pass



def main(args=None):

    rclpy.init(args=args) # start rospy

    jumping_node = jumping_state_machine() # make the node

    rclpy.spin(jumping_node)



    jumping_node.destroy_node() #when we're done, destroy everything
    rclpy.shutdown()


if __name__ == '__main__':

    main()