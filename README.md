# ROS作业报告
- 首先通过rostopic list查看数据包里的所有话题
```
/camera/color/camera_info
/camera/color/image_raw
/camera/depth/camera_info
/camera/depth/image_rect_raw
/clock
/imu/data_raw
/odom
/rosout
/rosout_agg
/rslidar_points
/scan
/tf
/tf_static
```
- 在空间里创建功能包
```bash
catkin_create_pkg show_imu std_msgs roscpp sensor_msgs
```
- src目录下写入show_imu.cpp和show_imu.h文件（头文件分离）
```cpp
void chatterCallback(const sensor_msgs::Imu::ConstPtr &msg)
{
    ROS_INFO("geometry_msgs/Quaternion orientation");
    ROS_INFO("float64 x: %.2lf", msg->orientation.x);
    ROS_INFO("float64 y: %.2lf", msg->orientation.y);
    ROS_INFO("float64 z: %.2lf", msg->orientation.z);
    ROS_INFO("float64 w: %.2lf", msg->orientation.w);
    ROS_INFO("-----------------------------------");
}
``````
- 通过ROS_INFO函数和指针展示数据
```cpp
int main(int argc, char **argv)
{//初始化节点
    ros::init(argc, argv, "show_imu_node"); 
    //自己创建了个句柄
    ros::NodeHandle nh;
    //订阅且调用了数据的话题，使用了回调函数chatterCallback
    ros::Subscriber sub = nh.subscribe("/imu/data_raw", 10, chatterCallback);
    ros::spin();//循环
    return 0;
}
```
- 同理展示odo数据不多赘述(代码来自ROS.INDEX官网)

### 使用opencv库来查看颜色与深度相机数据
```cpp
void colorImageCallback(const sensor_msgs::ImageConstPtr& msg)
{
    try
    {
        cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);

        // Display color image using OpenCV
        cv::imshow("Color Camera", cv_ptr->image);
        cv::waitKey(1);
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("cv_bridge exception: %s", e.what());
    }
}
```
- 代码来自拷打gpt实际上就是调用cv库里的窗口函数来展示信息（前人的力量）
- 然后就是在CMakeLists修改一点点信息
需要
```
find_package(OpenCV REQUIRED)
include_directories(
  ${OpenCV_INCLUDE_DIRS}
)
add_executable(color_camera_display_node src/color_camera_display_node.cpp)
target_link_libraries(color_camera_display_node  ${OpenCV_LIBS})
```
- 实际上也就是去寻找opencv库并且进行一个动态链接库的过程，深度相机也非常相似

### 最后任务4也是做了个边缘识别（源自CSDN）非常的简单调库，其实和颜色相机识别没有多大的区别


## 总结一下通过这次作业我习得了什么
1. catkin_make /catkin_create_pkg等系列cmake工具
2. ros中topic话题以及不同话题之间的订阅方式   主要学习资料（https://www.bilibili.com/video/BV1zt411G7Vn/） 
3. cmakelists中修改部分内容成功编译文件
4. 初步熟悉了cv库和pcl库的调用，会进行一定的修改来实现功能
5. git仓库的使用来实现源码储存
