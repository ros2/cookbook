#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::node::Node::make_shared("minimal_talker");
  auto publisher = node->create_publisher<std_msgs::msg::String>("chatter");
  auto message = std::make_shared<std_msgs::msg::String>();
  auto publish_count = 1;
  rclcpp::WallRate rate(2);
  while (rclcpp::ok()) {
    message->data = "Hello, world! " + std::to_string(publish_count++);
    std::cout << "Publishing: [" << message->data << "]" << std::endl;
    publisher->publish(message);
    rclcpp::spin_some(node);
    rate.sleep();
  }
  return 0;
}
