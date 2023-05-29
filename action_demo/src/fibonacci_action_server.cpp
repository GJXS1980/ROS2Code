#include <memory>

#include "action_demo/action/fibonacci.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "action_demo/visibility_control.h"

namespace action_demo
{
  class FibonacciActionServer : public rclcpp::Node
  {
    public:
      using Fibonacci = action_demo::action::Fibonacci;
      using GoalHandleFibonacci = rclcpp_action::ServerGoalHandle<Fibonacci>;
      // 构造函数,创建Fibonacci action的服务器
      explicit FibonacciActionServer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
      : Node("fibonacci_action_server", options)
      {
        using namespace std::placeholders;
        // 创建Fibonacci action的服务器
        this->action_server_ = rclcpp_action::create_server<Fibonacci>(
          this->get_node_base_interface(),
          this->get_node_clock_interface(),
          this->get_node_logging_interface(),
          this->get_node_waitables_interface(),
          "fibonacci",
          std::bind(&FibonacciActionServer::handle_goal, this, _1, _2),
          std::bind(&FibonacciActionServer::handle_cancel, this, _1),
          std::bind(&FibonacciActionServer::handle_accepted, this, _1));
      }

    private:
      rclcpp_action::Server<Fibonacci>::SharedPtr action_server_;

      rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const Fibonacci::Goal> goal)
      {
        (void)uuid;
        RCLCPP_INFO(this->get_logger(), "Received goal request with order %d", goal->order);
        // The Fibonacci action uses int32 for the return of sequences, which means it can only
        // hold 2^31-1 (2147483647) before wrapping negative in two's complement.  Based on empirical
        // tests, that means that an order of > 46 will cause wrapping, so we don't allow that here.
        // Fibonacci action使用int32来表示数列,即最大只能表示2^31-1(2147483647)个数,超过会溢出。
        // 根据实验测试,大于46的order会导致溢出,因此在此限制order不能大于46。
        if (goal->order > 46) 
        {
          return rclcpp_action::GoalResponse::REJECT;
        }
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
      }
      // 处理取消请求
      rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandleFibonacci> goal_handle)
      {
        RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
        (void)goal_handle;
        return rclcpp_action::CancelResponse::ACCEPT;
      }
      // 处理接受的目标
      void handle_accepted(const std::shared_ptr<GoalHandleFibonacci> goal_handle)
      {
        using namespace std::placeholders;
        // this needs to return quickly to avoid blocking the executor, so spin up a new thread
        // 为了避免阻塞执行器，该函数需要尽快返回，因此在新线程中执行。
        std::thread{std::bind(&FibonacciActionServer::execute, this, _1), goal_handle}.detach();
      }
      // 执行目标处理
      void execute(const std::shared_ptr<GoalHandleFibonacci> goal_handle)
      {
        RCLCPP_INFO(this->get_logger(), "Executing goal");
        rclcpp::Rate loop_rate(1);
        const auto goal = goal_handle->get_goal();
        auto feedback = std::make_shared<Fibonacci::Feedback>();
        auto & sequence = feedback->partial_sequence;
        sequence.push_back(0);
        sequence.push_back(1);
        auto result = std::make_shared<Fibonacci::Result>();

        for (int i = 1; (i < goal->order) && rclcpp::ok(); ++i) 
        {
          // Check if there is a cancel request
          // 检查是否有取消请求
          if (goal_handle->is_canceling()) {
            result->sequence = sequence;
            goal_handle->canceled(result);
            RCLCPP_INFO(this->get_logger(), "Goal canceled");
            return;
          }
          // Update sequence
          // 更新数列
          sequence.push_back(sequence[i] + sequence[i - 1]);
          // Publish feedback
          // 发布反馈
          goal_handle->publish_feedback(feedback);
          RCLCPP_INFO(this->get_logger(), "Publish feedback");

          loop_rate.sleep();
        }

        // Check if goal is done
        // 检查目标是否完成
        if (rclcpp::ok()) 
        {
          result->sequence = sequence;
          goal_handle->succeed(result);
          RCLCPP_INFO(this->get_logger(), "Goal succeeded");
        }
      }
  };  // class FibonacciActionServer

}  // namespace action_demo

RCLCPP_COMPONENTS_REGISTER_NODE(action_demo::FibonacciActionServer)