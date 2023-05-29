#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
import time
from rclpy.node import Node
from rclpy.action import ActionServer
from action_demo.action import Fibonacci

class FibonacciActionServer(Node):
    def __init__(self):
        # 创建名为fibonacci_action_server的节点
        super().__init__('fibonacci_action_server')
        # 创建名为fibonacci,类型为Fibonacci的action服务器
        self._action_server = ActionServer(self, Fibonacci, 'fibonacci',self.execute_callback)

    def execute_callback(self, goal_handle):
        """
        * 功能： 回调函数,根据请求函数返回结果，发布处理过程
        """
        # 输出执行目标的日志信息
        self.get_logger().info('Executing goal...')

        # 创建反馈消息并初始化partial_sequence字段
        feedback_msg = Fibonacci.Feedback()
        feedback_msg.partial_sequence = [0, 1]
        print(goal_handle.request.order)

        # 计算Fibonacci数列并发送反馈
        for i in range(1, goal_handle.request.order):
            # 计算下一个Fibonacci数列的值
            feedback_msg.partial_sequence.append(
                feedback_msg.partial_sequence[i] + feedback_msg.partial_sequence[i-1])
            # 输出反馈信息到日志
            self.get_logger().info('Feedback:{0}'.format(feedback_msg.partial_sequence))
            # 发布反馈消息
            goal_handle.publish_feedback(feedback_msg)
            time.sleep(1)
        # 标记目标已成功完成
        goal_handle.succeed()
        # 创建结果消息并设置sequence字段
        result = Fibonacci.Result()
        result.sequence = feedback_msg.partial_sequence

        # 返回结果消息
        return result

def main(args=None):
    rclpy.init(args=args)
    fibonacci_action_server = FibonacciActionServer()
    rclpy.spin(fibonacci_action_server)

if __name__ == '__main__':
    main()



