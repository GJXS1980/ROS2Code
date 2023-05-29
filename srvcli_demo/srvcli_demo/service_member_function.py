#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
import time
from rclpy.node import Node
from std_msgs.msg import String
from srvcli_demo.srv import AddTwoInts

class MinimalService(Node):
    def __init__(self):
        # 创建名为minimal_publisher的节点
        super().__init__('minimal_service')
        # 创建名为topic_test,类型为String,queue size为10的话题
        self.srv = self.create_service(AddTwoInts, 'add_two_ints', self.add_two_ints_callback)

    def add_two_ints_callback(self, request, response):
        """
        * 功能： 回调函数,计算累加值
        """
        response.sum = request.a + request.b
        self.get_logger().info('Incoming request\na: %d b: %d' % (request.a, request.b))
        return response

def main(args=None):
    rclpy.init()
    minimal_service = MinimalService()
    rclpy.spin(minimal_service)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
