#include "show_odo.h"
void odometryCallback(const nav_msgs::Odometry::ConstPtr &msg)
{
    ROS_INFO("Position: x=%f, y=%f, z=%f",
             msg->pose.pose.position.x,
             msg->pose.pose.position.y,
             msg->pose.pose.position.z);
    ROS_INFO("Orientation: x=%f, y=%f, z=%f, w=%f",
             msg->pose.pose.orientation.x,
             msg->pose.pose.orientation.y,
             msg->pose.pose.orientation.z,
             msg->pose.pose.orientation.w);
    ROS_INFO("----------------------------------------------");
}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "show_odo_node");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/odom", 10, odometryCallback);
    ros::spin();
    return 0;
}