cmake_minimum_required(VERSION 2.8.3)
project(lidar_display_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  sensor_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(lidar_display_node src/lidar_display_node.cpp)
target_link_libraries(lidar_display_node ${catkin_LIBRARIES})
