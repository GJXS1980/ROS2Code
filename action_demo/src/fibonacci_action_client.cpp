#include <memory>
#include <string>
#include <sstream>

#include "action_demo/action/fibonacci.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "action_demo/visibility_control.h"

namespace action_demo
{
class FibonacciActionClient : public rclcpp::Node
{
  public:
    using Fibonacci = action_demo::action::Fibonacci;
    using GoalHandleFibonacci = rclcpp_action::ClientGoalHandle<Fibonacci>;

    explicit FibonacciActionClient(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions())
    : Node("fibonacci_action_client", node_options)
    {
      // 创建Fibonacci action的客户端
      this->client_ptr_ = rclcpp_action::create_client<Fibonacci>(
        this->get_node_base_interface(),
        this->get_node_graph_interface(),
        this->get_node_logging_interface(),
        this->get_node_waitables_interface(),
        "fibonacci");
      // 创建定时器,定时调用send_goal函数
      this->timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&FibonacciActionClient::send_goal, this));
    }

    void send_goal()
    {
      using namespace std::placeholders;
      // 取消定时器
      this->timer_->cancel();
      // 等待action server可用
      if (!this->client_ptr_->wait_for_action_server(std::chrono::seconds(10))) 
      {
        RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting");
        rclcpp::shutdown();
        return;
      }
      // 创建目标消息
      auto goal_msg = Fibonacci::Goal();
      goal_msg.order = 10;

      RCLCPP_INFO(this->get_logger(), "Sending goal");
      // 设置发送目标消息的选项，包括回调函数
      auto send_goal_options = rclcpp_action::Client<Fibonacci>::SendGoalOptions();
      send_goal_options.goal_response_callback = std::bind(&FibonacciActionClient::goal_response_callback, this, _1);
      send_goal_options.feedback_callback = std::bind(&FibonacciActionClient::feedback_callback, this, _1, _2);
      send_goal_options.result_callback = std::bind(&FibonacciActionClient::result_callback, this, _1);
      // 异步发送目标消息
      this->client_ptr_->async_send_goal(goal_msg, send_goal_options);
    }

  private:
    rclcpp_action::Client<Fibonacci>::SharedPtr client_ptr_;  // Fibonacci action的客户端指针
    rclcpp::TimerBase::SharedPtr timer_;  // 定时器指针

    // 目标消息回调函数
    void goal_response_callback(GoalHandleFibonacci::SharedPtr goal_handle)
    {
      // 如果goal_handle为空,则表示目标被服务器拒绝
      if (!goal_handle) 
      {
        RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
        rclcpp::shutdown();
      } 
      else 
      {
        RCLCPP_INFO(this->get_logger(), "Goal accepted by server, waiting for result");
      }
    }
    // 反馈消息回调函数
    void feedback_callback(GoalHandleFibonacci::SharedPtr, const std::shared_ptr<const Fibonacci::Feedback> feedback)
    {
      std::stringstream ss;
      ss << "Next number in sequence received: ";
      for (auto number : feedback->partial_sequence) 
      {
        ss << number << " ";
      }
      RCLCPP_INFO(this->get_logger(), "%s", ss.str().c_str());
    }

    // 结果消息回调函数
    void result_callback(const GoalHandleFibonacci::WrappedResult & result)
    {
      // 根据返回的结果代码进行处理
      switch (result.code) 
      {
        case rclcpp_action::ResultCode::SUCCEEDED:
          break;
        case rclcpp_action::ResultCode::ABORTED:
          RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
          return;
        case rclcpp_action::ResultCode::CANCELED:
          RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
          return;
        default:
          RCLCPP_ERROR(this->get_logger(), "Unknown result code");
          return;
      }
      std::stringstream ss;
      ss << "Result received: ";
      for (auto number : result.result->sequence) 
      {
        ss << number << " ";
      }
      RCLCPP_INFO(this->get_logger(), "%s", ss.str().c_str());
      rclcpp::shutdown();
    }
};  // class FibonacciActionClient

}  // namespace action_demo

RCLCPP_COMPONENTS_REGISTER_NODE(action_demo::FibonacciActionClient)