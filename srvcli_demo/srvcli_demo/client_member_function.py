#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import rclpy
from rclpy.node import Node
from srvcli_demo.srv import AddTwoInts

class MinimalClientAsync(Node):
    def __init__(self):
        # 创建名为minimal_client_async的节点
        super().__init__('minimal_client_async')
        # 创建名为add_two_ints,类型为AddTwoInts的服务客户端
        self.cli = self.create_client(AddTwoInts, 'add_two_ints')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again ...')
        self.req = AddTwoInts.Request()


    def send_request(self, a, b):
        """
        * 功能： 回调函数,计算累加值
        """
        self.req.a = a
        self.req.b = b 
        # 发送a, b值
        self.future = self.cli.call_async(self.req)
        # 等待服务完成
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

def main(args=None):
    rclpy.init()
    minimal_client = MinimalClientAsync()
    response = minimal_client.send_request(int(sys.argv[1]), int(sys.argv[2]))
    minimal_client.get_logger().info(
        'Result of add_two_ints: for %d + %d = %d' %
        (int(sys.argv[1]), int(sys.argv[2]), response.sum))
    minimal_client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
