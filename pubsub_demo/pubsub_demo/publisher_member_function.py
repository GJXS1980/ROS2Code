#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class MinimalPublisher(Node):
    def __init__(self):
        # 创建名为minimal_publisher的节点
        super().__init__('minimal_publisher')
        # 创建名为topic_test,类型为String,queue size为10的话题
        self.publisher_ = self.create_publisher(String, 'topic_test', 10)
        timer_period = 0.5
        # 创建每0.5s运行timer_callback函数的定时器
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0


    def timer_callback(self):
        """
        * 功能： 回调函数,打印Hello World
        """
        msg = String()
        msg.data = 'Hello World: %d' % self.i
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s' % msg.data)
        self.i += 1

def main(args=None):
    rclpy.init(args=args)
    minimal_publisher = MinimalPublisher()
    rclpy.spin(minimal_publisher)
    minimal_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
