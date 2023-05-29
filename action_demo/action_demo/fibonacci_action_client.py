#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from action_demo.action import Fibonacci

class FibonacciActionClient(Node):
    def __init__(self):
        # 创建名为fibonacci_action_client的节点
        super().__init__('fibonacci_action_client')
        # 创建名为fibonacci,类型为Fibonacci的action客户端
        self._action_client = ActionClient(self, Fibonacci, 'fibonacci')

    def send_goal(self, order):
        """
        * 功能： 发送目标函数Goal Service
        """
        # Fibonacci.Goal是一个定义了用于Fibonacci序列生成的目标消息类型
        goal_msg = Fibonacci.Goal()
        goal_msg.order = order
        # 等待Action服务器连接
        self._action_client.wait_for_server()
        # 异步发送目标消息并设置反馈回调函数
        self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        # 添加完成回调函数，该回调函数将在目标发送完成时被调用
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        """
        * 功能： 反馈过程量
        """
        # 从Future对象获取GoalHandle对象
        goal_handle = future.result()
        # 检查Goal是否被接受
        if not goal_handle.accepted:
            # 如果Goal被拒绝,则输出相应信息
            self.get_logger().info('Goal rejected:(')
            return
         # 如果Goal被接受,则输出相应信息
        self.get_logger().info('Goal accepted:)')
        # 获取结果的Future对象
        self._get_result_future = goal_handle.get_result_async()
        # 添加结果回调函数，该回调函数将在结果可用时被调用
        self._get_result_future.add_done_callback(self.get_result_callback)
    
    def get_result_callback(self, future):
        """
        * 功能： 处理action返回结果
        """
        # 从Future对象中获取结果并存储在result变量中,阻塞等待操作完成并获取结果
        result = future.result().result
        # 输出结果的sequence字段到日志
        self.get_logger().info('Result:{0}'.format(result.sequence))
        # 关闭ROS2节点
        rclpy.shutdown()

    def feedback_callback(self, feedback_msg):
        """
        * 功能： 获取反馈函数
        """
        # 从feedback_msg中获取反馈信息并存储在feedback变量中
        feedback = feedback_msg.feedback
        # 输出反馈信息的partial_sequence字段到日志
        self.get_logger().info('Received feedback:{0}'.format(feedback.partial_sequence))

def main(args=None):
    rclpy.init(args=args)
    action_client = FibonacciActionClient()
    action_client.send_goal(10)
    rclpy.spin(action_client)

if __name__ == '__main__':
    main()
