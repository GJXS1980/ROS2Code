#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class MinimalSubscriber(Node):
    def __init__(self):
        # 创建名为minimal_publisher的节点
        super().__init__('minimal_subscriber')
        # 订阅名为topic_test,类型为String,queue size为10的话题
        self.subscription = self.create_subscription(String, 'topic_test', self.listener_callback, 10)
        self.subscription

    def listener_callback(self, msg):
        """
        * 功能： 回调函数,打印I heard
        """
        self.get_logger().info('I heard: "%s' % msg.data)


def main(args=None):
    rclpy.init(args=args)
    minimal_subscriber = MinimalSubscriber()
    rclpy.spin(minimal_subscriber)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
