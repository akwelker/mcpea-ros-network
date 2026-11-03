#!/usr/bin/python3
'''
Adam Welker     Utah Robotics Center        Oct. 2026


zeroing_machine.py: A state machine that correctly tares and zeros the robot leg
at the dynamic equilibrium of the MC-PEA, given that the leg is unloaded and 
sitting statically within a single equilibrium
'''
import rclpy
from rclpy.node import Node

from spi_interface.msg import McpeaCommand
from spi_interface.msg import McpeaTelemetry
from std_srvs.srv import Trigger

import numpy as np
import actuator_command.actuator_command_params as param
from enum import Enum

from time import time, sleep
from numpy import pi,sin,abs

TIMOUT_TIME = 60*5 # minutes
MAXIMUM_PULL_TORQUE = 0.25 #Nm
PULL_TORQUE_PERIOD  = 10. # s
OMEGA = 2.*pi/PULL_TORQUE_PERIOD # rad/s


def get_pulling_waveform(time:float)->float:

    if(abs(time) > PULL_TORQUE_PERIOD/2):

        return 0.

    else:

        return MAXIMUM_PULL_TORQUE*sin(OMEGA * time)

class States(Enum):

    Start = 0
    Pulling_Back = 1
    Intitial_Taring = 2
    Pulling_Forward = 3
    Finding_Zero = 4
    Final_Zeroing = 5
    Finish = 6



class Zeroing_State_Machine(Node):

    def __init__(self):
        '''
        Class constructor. Makes the node and internal variables
        '''

        super().__init__('Zeroing_state_machine')

        self.command_msg = McpeaCommand()

        self._command_publisher = self.create_publisher(McpeaCommand,'actuator_command',2)
        self._telemetry_subscriber = self.create_subscription(McpeaTelemetry,'actuator_telemetry',self.telemetry_callback,2)
        self._enable_client = self.create_client(Trigger,'actuator_enable')
        self._disable_client = self.create_client(Trigger,'actuator_disable')

        self.publish_timer = self.create_timer(1/500,self.timer_callback)

        self._zero_client = self.create_client(Trigger,'zero_joint_angle')

        self.state = States.Start

        self.joint_angle = 0
        self.joint_velocity = 0
        self.joint_accel = 0

    def timer_callback(self):

        self._command_publisher.publish(self.command_msg)


    def telemetry_callback(self,msg:McpeaTelemetry):

        self.joint_angle = msg.joint_position
        self.joint_velocity = msg.joint_velocity
        self.joint_accel = msg.accel_1


    def run_state_machine(self):
        '''
        Runs a state machine that zeros the actuator. Assumes that the MC-PEA
        is unloaded and at rest in an equilibrium
        '''

        is_finished = False
        started_time = time()

        self.enable_motor()

        while (not is_finished) and (time() - started_time <= TIMOUT_TIME):
            rclpy.spin_once(self)

            match self.state:

                case States.Start:

                    self.ref_time = time()
                    self.state = States.Pulling_Back
                    self.get_logger().info("Pulling back actuator to -x_k...")
                    

                case States.Pulling_Back:

                    curr_time = time() - self.ref_time
                    self.regulate_torque(-1*get_pulling_waveform(curr_time))

                    if curr_time >= PULL_TORQUE_PERIOD and (abs(self.joint_velocity)<=0.5):

                        self.state = States.Intitial_Taring
                        self.get_logger().info("Taring Actuator...")
                    

                case States.Intitial_Taring:
                    
                    self.do_nothing()
                    zero_request = Trigger.Request()
                    response = self._zero_client.call_async(zero_request)
                    rclpy.spin_until_future_complete(self,response,timeout_sec=2.0)


                    if response.done():

                        if  response.result().success == True and abs(self.joint_angle) <= 0.005: # check to see if joint angle is actually zeroed

                            self.state = States.Pulling_Forward
                            self.ref_time = time()
                            self.get_logger().info("Pushing back actuator to x_k...")

                    else:

                        self.get_logger().warn("Zeroing request timed out. Retrying...")
                        response.cancel()


                case States.Pulling_Forward:

                    curr_time = time() - self.ref_time
                    self.regulate_torque(get_pulling_waveform(curr_time))

                    if curr_time >= PULL_TORQUE_PERIOD and (abs(self.joint_velocity)<=0.5):
                        self.ref_angle = self.joint_angle/2
                        self.state = States.Finding_Zero
                        self.get_logger().info(f"Band of static friction found to be {self.ref_angle} deg. wide. Finding Center...")

                case States.Finding_Zero:

                    self.regulate_angle(self.ref_angle)

                    if abs(self.joint_angle - self.ref_angle) <= 0.005 and abs(self.joint_velocity<=0.5):

                        self.state = States.Final_Zeroing
                        self.get_logger().info("Arrived at reference angle. Performing final tare...")
                    
                case States.Final_Zeroing:

                    self.do_nothing()
                    zero_request = Trigger.Request()
                    response = self._zero_client.call_async(zero_request)
                    rclpy.spin_until_future_complete(self,response,timeout_sec=2.0)


                    if response.done():
                    
                        if  response.result().success == True and abs(self.joint_angle) <= 0.005: # check to see if joint angle is actually zeroed

                            self.state = States.Finish

                    else:

                        self.get_logger().warn("Zeroing request timed out. Retrying...")
                        response.cancel()

                case States.Finish:

                    self.do_nothing()
                    self.get_logger().info("State Machine finished zeroing the joint angle!")
                    is_finished = True

                    pass

            if time() - started_time >= TIMOUT_TIME:

                self.get_logger().warning("State Machine unable to complete zeroing process")


        self.disable_motor()

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

        self.get_logger().error('Bode was not able to enable the motor!')
        return False


    def disable_motor(self):
        '''
        disables the motor. Duh
        '''

        self.get_logger().warn('Enabling Motor!')

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


    def regulate_angle(self, reference:float)->None:

        self.command_msg = McpeaCommand()
        self.command_msg.control_mode = param.PID_position
        self.command_msg.current_limit = param.safe_current_limit
        self.command_msg.torque_limit = param.std_torque_limit
        self.command_msg.data_1 = reference # setpoint 
        self.command_msg.data_2 = param.std_kp
        # self.command_msg.data_3 = param.std_ki
        self.command_msg.data_4 = param.std_kd

        return

    def regulate_torque(self,reference:float)->None:

        self.command_msg = McpeaCommand()
        self.command_msg.control_mode = param.torque_control
        self.command_msg.current_limit = param.safe_current_limit
        self.command_msg.torque_limit = param.std_torque_limit
        self.command_msg.data_1 = reference # setpoint 

        return


    def do_nothing(self)->None:

        self.command_msg = McpeaCommand()



def main(args=None):

    rclpy.init(args=args) # start rospy

    regulating_node = Zeroing_State_Machine() # make the node

    regulating_node.run_state_machine()

    rclpy.spin(regulating_node)

    regulating_node.destroy_node() #when we're done, destroy everything
    rclpy.shutdown()


if __name__ == '__main__':

    main()