cmake_minimum_required(VERSION 2.8.3)
project(depth_camera_display_pkg)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  sensor_msgs
  cv_bridge
  image_transport
)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(OpenCV REQUIRED)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(depth_camera_display_node src/depth_camera_display_node.cpp)
target_link_libraries(depth_camera_display_node ${catkin_LIBRARIES} ${OpenCV_LIBS})
