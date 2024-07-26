#include "ros/ros.h"
#include "bingda_practices/RGB_LED.h"
#include "std_msgs/String.h"

void RGB_LED_Callback(bingda_practices::RGB_LED msg)
{
    // 接收到RGB_LED消息后，打印消息中的ID，RGB值和Others值
    ROS_INFO("Received RGB_LED Message: ID = %d, RGB = (%d, %d, %d), Others = (%f, %f)",
             msg.ID, msg.RGB[0], msg.RGB[1], msg.RGB[2], msg.Others[0], msg.Others[1]);
}
int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "RGB_LED_Listener");
    ros::NodeHandle n;
    // 订阅RGB_LED消息，并设置回调函数为RGB_LED_Callback
    ros::Subscriber sub = n.subscribe("RGB_LED", 1000, RGB_LED_Callback);
    // 循环等待回调函数
    ros::spin();
    return 0;
}
