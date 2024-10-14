#include <rclcpp/rclcpp.hpp>

#include <std_msgs/msg/string.hpp>

using namespace std::chrono_literals;

namespace ros2_examples  //使用命名空间
{

/* class PublisherExample //{ */

class PublisherExample : public rclcpp::Node
{
public:
  PublisherExample(rclcpp::NodeOptions options);

private:
  // | -------------------- member variables -------------------- |


  // | ----------------------- publishers ----------------------- |

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;


  // | ------------------------- timers ------------------------- |

  rclcpp::TimerBase::SharedPtr timer_;

  // | ------------------------- methods ------------------------ |
  void callback();//一定记得声明回调函数
};

//}

/* PublisherExample() //{ */

PublisherExample::PublisherExample(rclcpp::NodeOptions options)
: Node("publisher_example", options)
{
  RCLCPP_INFO(get_logger(), "[PublisherExample]: initializing");

  // | ------------------------ publisher ----------------------- |

  publisher_ = create_publisher<std_msgs::msg::String>("~/topic_publisher", 10);


  // | -------------------------- timer ------------------------- |

  timer_ =
    create_wall_timer(
    1000ms,
    std::bind(&PublisherExample::callback, this));//1000ms 执行一次回调函数


  // | --------------------- finish the init -------------------- |

  RCLCPP_INFO(get_logger(), "[PublisherExample]: initialized=======完成初始化");
}

//}

// | ------------------------ callbacks ----------------------- |



void PublisherExample::callback()
{
  publisher_->publish(
    std_msgs::msg::String().set__data(
      "消息发送成功！！！！."));
}


}  // namespace ros2_examples

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(ros2_examples::PublisherExample)
