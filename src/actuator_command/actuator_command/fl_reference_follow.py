#!/usr/bin/python3
'''
Adam Welker     Utah Robotics Center        Oct. 2026


regulator.py: Mostly a test program. Regulates the leg to 0 joint angle.
'''
import rclpy
from rclpy.node import Node

from spi_interface.msg import McpeaCommand
from std_msgs.msg import Float32
from std_srvs.srv import Trigger

import numpy as np
import actuator_command.actuator_command_params as param

from numpy import radians
from time import sleep



class Regulator(Node):

    def __init__(self):
        '''
        Class constructor. Makes the node and internal variables
        '''

        super().__init__('Regulator_Node')

        self._command_publisher = self.create_publisher(McpeaCommand,'actuator_command',2)
        self._reference_subscriber = self.create_subscription(Float32, 'reference_signal',self.reference_callback,2)
        self._enable_client = self.create_client(Trigger,'actuator_enable')
        self._disable_client = self.create_client(Trigger,'actuator_disable')


        self._timer = self.create_timer(1/500,self.publish_callback)

        self.command_msg = McpeaCommand()
        self.command_msg.control_mode = param.feedback_linearization
        self.command_msg.current_limit = param.std_current_limit
        self.command_msg.torque_limit = param.std_torque_limit
        self.command_msg.data_1 = 0.0
        self.command_msg.data_2 = param.std_kp
        self.command_msg.data_3 = param.std_kd
        self.command_msg.data_5 = 1. # gain on magnetic compensator

        # Publish a message to enable the motor
        self.get_logger().warn('Enabling Motor!')

        self.enable_motor()



    def __del__(self):

        self.disable_motor()

    def reference_callback(self,msg:Float32):

        self.command_msg.data_1 = msg.data


    def publish_callback(self):


        self._command_publisher.publish(self.command_msg)


    def enable_motor(self):
        '''
        Enables the motor. Duh. Got some help from claude on this one (to stop
        code blocking, understanding .spin_until_future_complete)
        '''
        self.get_logger().warn('Enabling Motor!')

        # Don't send requests into the void
        while not self._enable_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn('Enable service not available, waiting...')

        for attempt in range(1000):
            future = self._enable_client.call_async(Trigger.Request())
            rclpy.spin_until_future_complete(self, future, timeout_sec=2.0)

            if not future.done():
                self.get_logger().warn('Enable request timed out')
                future.cancel()
            elif future.result() is not None and future.result().success:
                self.get_logger().info('Motor Enabled!')
                return True
            else:
                self.get_logger().warn('Could not enable motor!')

            sleep(0.1)  # back off between retries

        self.get_logger().error('Node was not able to enable the motor!')
        return False


    def disable_motor(self):
        '''
        disables the motor. Duh
        '''
        self.command_msg.control_mode = 0.0

        self.get_logger().warn('Disabling Motor!')

        # Don't send requests into the void
        while not self._disable_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn('Enable service not available, waiting...')

        for attempt in range(1000):
            future = self._disable_client.call_async(Trigger.Request())
            rclpy.spin_until_future_complete(self, future, timeout_sec=2.0)

            if not future.done():
                self.get_logger().warn('Enable request timed out')
                future.cancel()
            elif future.result() is not None and future.result().success:
                self.get_logger().info('Motor Disabled!')
                return True
            else:
                self.get_logger().warn('Could not enable motor!')

            sleep(0.1)  # back off between retries

        self.get_logger().error('Node was not able to disable the motor!')
        return False

def main(args=None):

    rclpy.init(args=args) # start rospy

    regulating_node = Regulator() # make the node

    rclpy.spin(regulating_node)

    regulating_node.destroy_node() #when we're done, destroy everything
    rclpy.shutdown()


if __name__ == '__main__':

    main()