#!/usr/bin/env python3
"""
Adam Welker     Utah Robotics Center        NOV 26

WRITTEN BY CLAUDE SONNET 5.5

ROS 2 Humble node that publishes an integer on the "test_number" topic.

Run it in its own terminal:
    source /opt/ros/humble/setup.bash
    python3 test_number_publisher.py

Controls:
    Up arrow    -> increase test_number by 1
    Down arrow  -> decrease test_number by 1
    Ctrl-C      -> quit

test_number starts at 0.
"""

import os
import select
import sys
import termios
import tty

import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32

PUBLISH_RATE_HZ = 20.0   # how often the current value is published
KEY_POLL_RATE_HZ = 100.0  # how often the keyboard is checked

# Arrow key escape sequences (normal mode and application-cursor mode)
UP_SEQUENCES = ("\x1b[A", "\x1bOA")
DOWN_SEQUENCES = ("\x1b[B", "\x1bOB")


class TestNumberPublisher(Node):
    def __init__(self):
        super().__init__("test_number_publisher")

        self.publisher_ = self.create_publisher(Int32, "test_number", 10)
        self.test_number = 0

        self.fd = sys.stdin.fileno()
        self.old_term_settings = termios.tcgetattr(self.fd)
        # cbreak: keys are delivered immediately without Enter and without echo,
        # but Ctrl-C still works.
        tty.setcbreak(self.fd)

        self.create_timer(1.0 / KEY_POLL_RATE_HZ, self.poll_keyboard)
        self.create_timer(1.0 / PUBLISH_RATE_HZ, self.publish_number)

        print("Up/Down arrows change test_number. Ctrl-C to quit.")
        self.print_value()

    def poll_keyboard(self):
        """Read any pending keystrokes without blocking."""
        changed = False

        while select.select([self.fd], [], [], 0)[0]:
            data = os.read(self.fd, 1024).decode(errors="ignore")
            if not data:
                break

            i = 0
            while i < len(data):
                chunk = data[i:i + 3]
                if chunk in UP_SEQUENCES:
                    self.test_number += 1
                    changed = True
                    i += 3
                elif chunk in DOWN_SEQUENCES:
                    self.test_number -= 1
                    changed = True
                    i += 3
                else:
                    i += 1

        if changed:
            self.print_value()
            self.publish_number()  # publish immediately on change

    def publish_number(self):
        msg = Int32()
        msg.data = self.test_number
        self.publisher_.publish(msg)

    def print_value(self):
        print(f"\rtest_number: {self.test_number}      ", end="", flush=True)

    def restore_terminal(self):
        termios.tcsetattr(self.fd, termios.TCSADRAIN, self.old_term_settings)
        print()  # move off the in-place status line


def main(args=None):
    if not sys.stdin.isatty():
        print("This node needs an interactive terminal (stdin is not a TTY).")
        return

    rclpy.init(args=args)
    node = TestNumberPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.restore_terminal()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
