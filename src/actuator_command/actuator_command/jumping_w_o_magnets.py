#!/usr/bin/env python3
'''
Adam Welker     Utah Robotics Center        Oct. 2026


jumping_w_o_magnets.py: makes the leg jump, but without magnets engaged
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
from numpy import pi,sin,abs,radians, degrees
from scipy.signal import butter

# state machine parameters
TIME_OUT_PERIOD = 60*2.0 # 2 min in seconds
PULLBACK_ANGLE = 16.5 # degrees
LANDING_ANGLE = -0. # degrees
COMPRESSION_ANGLE = 13. #degrees
EXTENSION_ANGLE = -40. # degrees
LANDING_TORQUE = 0.5 #NM
INJECTION_TORQUE = -10. #nm
TRANSITION_ANGLE = -20


# filter parameters

f_c = 20
f_s = 500

alpha = f_c/(f_c + f_s/2./pi)


def low_pass(y_prev:float,x:float)->float:
    '''
    Return result for first order IIR filter

    '''
    return alpha*x + (1-alpha)*y_prev

#Boom angle filter parameters

class States(Enum):

    Start = 0
    Pulling_Back = 1
    Initial_Force_Injection = 2
    Final_Force_Injection = 7
    Flight = 3
    Landing = 4
    Compression = 5
    Finish = 6



class Jumping_State_Machine(Node):

    def __init__(self):
        '''
        Class constructor. Makes the node and internal variables
        '''

        super().__init__('Zeroing_state_machine')

        # Command of what we are doing
        self.command_msg = McpeaCommand()

        # Pubs/subs
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
        self.boom_angle = None

        self.prev_time = 0
        self.boom_vel = 0
        self.curr_torque = 0

    def timer_callback(self):

        self._command_publisher.publish(self.command_msg)


    def telemetry_callback(self, msg:McpeaTelemetry):

        self.joint_angle = msg.joint_position
        self.joint_velocity = msg.joint_velocity
        self.joint_accel = msg.accel_1

        if (self.boom_angle == None):

            self.boom_angle = degrees(msg.boom_angle)
            self.prev_time = time()
            
        else:

            prev_angle = self.boom_angle
            self.boom_angle = low_pass(self.boom_angle,degrees(msg.boom_angle))

            dt = time() - self.prev_time
            self.boom_vel = (self.boom_angle - prev_angle)/dt

            self.prev_time = time()


        self.curr_torque = msg.act_current*0.098*6

    def run_state_machine(self, num_jumps = 3):
        '''
        Runs a state machine that zeros the actuator. Makes the actuator jump
        three times
        '''

        is_finished = False
        started_time = time()
        jump_completed = 0

        self.enable_motor()

        while (not is_finished) and (time() - started_time <= TIME_OUT_PERIOD):
            rclpy.spin_once(self)

            match self.state:

                case States.Start:

                    self.regulate_angle(PULLBACK_ANGLE)
                    self.state = States.Pulling_Back
                    self.get_logger().info("Initializing Jump, pulling back!")

                case States.Pulling_Back:

                    if abs(self.joint_angle - PULLBACK_ANGLE) <= 1.0:

                        self.regulate_angle(EXTENSION_ANGLE)
                        self.state = States.Initial_Force_Injection
                        self.get_logger().info("Injecting Force!")
                        self.ref_time = time()


                case States.Initial_Force_Injection:


                    if self.joint_angle <= TRANSITION_ANGLE:

                        self.regulate_torque(INJECTION_TORQUE)
                        self.state = States.Final_Force_Injection
                        self.get_logger().info("Final Push!")
                        self.ref_time = time()

                    elif time() - self.ref_time >= 1.0:

                        self.get_logger().error("Did not ROA Transition.")
                        self.do_nothing()
                        self.state = States.Finish

                case States.Final_Force_Injection:

                    if self.joint_angle <= EXTENSION_ANGLE:

                        self.regulate_angle(EXTENSION_ANGLE)
                        self.state = States.Flight
                        jump_completed += 1
                        self.get_logger().info("Lift off!")

                    elif time() - self.ref_time >= 1.0:

                        self.get_logger().error("Did not detect lift off.")
                        self.do_nothing()
                        self.state = States.Finish
                        jump_completed += 1

                case States.Flight:

                    # check if the joint angle is somewhat cose to the landing angle and we have a torque spike

                    if self.boom_vel >= 3.0:

                        self.state = States.Landing
                        self.regulate_angle(LANDING_ANGLE)
                        self.get_logger().info('Detected Apogee!')


                case States.Landing:

                    if abs(self.joint_angle - LANDING_ANGLE) <= 1 and abs(self.joint_velocity) <= 0.5:
                    
                        self.state = States.Compression
                        self.regulate_angle(LANDING_ANGLE)
                        self.get_logger().info('Ready to Land!')

                    # elif self.joint_angle >= COMPRESSION_ANGLE and self.boom_vel <=  0.5:

                    #     self.get_logger().info("Detected early jump!")
                    #     if jump_completed > num_jumps:

                    #         self.state = States.Finish
                    #         self.do_nothing()

                    #     else:

                    #         self.feedback_linearization_regulate(EXTENSION_ANGLE)
                    #         self.state = States.Initial_Force_Injection
                    #         self.get_logger().info("Jumping Again!")
                    #         self.ref_time = time()



                case States.Compression:

                    # check to see if we're going up or have passed the compression max angle

                    if self.joint_angle >= COMPRESSION_ANGLE: #and self.boom_vel <=  0.25:

                        if jump_completed > num_jumps:

                            self.state = States.Finish
                            self.do_nothing()

                        else:

                            self.regulate_angle(EXTENSION_ANGLE)
                            self.state = States.Initial_Force_Injection
                            self.get_logger().info("Jumping Again!")
                            self.ref_time = time()
                

                case States.Finish:

                    self.do_nothing()
                    self.get_logger().info("Robot finished jumping! What a workout :)")
                    is_finished = True

                    pass

            if time() - started_time >= TIME_OUT_PERIOD:

                self.get_logger().warning("State Machine unable to jumping routine!")


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

        self.get_logger().error('Node was not able to enable the motor!')
        return False


    def disable_motor(self):
        '''
        disables the motor. Duh
        '''

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


    def regulate_angle(self, reference:float)->None:

        self.command_msg = McpeaCommand()
        self.command_msg.control_mode = param.PID_position
        self.command_msg.current_limit = param.std_current_limit
        self.command_msg.torque_limit = param.std_torque_limit
        self.command_msg.data_1 = radians(reference) # setpoint 
        self.command_msg.data_2 = param.std_kp
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

    jumping_node = Jumping_State_Machine() # make the node

    jumping_node.run_state_machine()

    rclpy.spin(jumping_node)

    jumping_node.destroy_node() #when we're done, destroy everything
    rclpy.shutdown()


if __name__ == '__main__':

    main()