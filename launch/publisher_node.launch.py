import launch
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode
import os

def generate_launch_description():

    ld = launch.LaunchDescription()

    pkg_name = "ros2_example"
    pkg_share_path = get_package_share_directory(pkg_name)

    namespace='hello'
    ld.add_action(ComposableNodeContainer(
        namespace='',
        name=namespace+'_publisher_example',
        package='rclcpp_components',
        executable='component_container_mt', # multi-threaded callback execution
        # executable='component_container', # single-threaded callback execution
        composable_node_descriptions=[
            ComposableNode(
                package=pkg_name,
                plugin='ros2_examples::PublisherExample',
                namespace=namespace,
                name='publisher_',
 #               parameters=[
 #                 pkg_share_path + '/config/publisher_example.yaml',
 #               ],
                remappings=[
                    # topics
                    #/前一个是被映射的对象，后一个是映射的对象/#
                    ("~/topic_publisher", "~/topic_publisher_out"),
 #                   ("~/topic_slow_out", "~/topic_slow"),
 #                   ("~/topic_irregular_out", "~/topic_irregular"),
                ],
            ),
        ],
        output='screen',
    ))

    return ld
