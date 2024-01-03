// lidar_display_pkg/src/lidar_display_node.cpp
#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "lidar_display_node");
    ros::NodeHandle nh;

    // Subscribe to lidar point cloud topic
    ros::Subscriber sub = nh.subscribe<sensor_msgs::PointCloud2>("/rslidar_points", 1,
                                                                 [](const sensor_msgs::PointCloud2::ConstPtr &msg)
                                                                 {
                                                                     // Display point cloud in RViz
                                                                     ROS_INFO("Received point cloud data");
                                                                 });

    ros::spin();

    return 0;
}
