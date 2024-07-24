#include "ros/ros.h"
#include "bingda_practices/RGB_LED.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "RGB_LED_Publisher"); // 初始化ROS节点
    ros::NodeHandle n; // 创建节点句柄
    ros::Publisher RGB_LED_Publisher = n.advertise<bingda_practices::RGB_LED>("rgb_led", 10); // 发布rgb_led主题
    ros::Rate loop_rate(10); // 设置循环频率为10Hz

    int count = 0;
    ROS_INFO("RGB_LED_Publisher Start Publishing");

    while (ros::ok())
    {
        bingda_practices::RGB_LED msg;
        msg.ID = count;
        msg.RGB[0] = 40;
        msg.RGB[1] = 50;
        msg.RGB[2] = 60;
        msg.Others[0] = 3.8;
        msg.Others[1] = 4.9;
        RGB_LED_Publisher.publish(msg);
        loop_rate.sleep();
        ++count;
    }
    return 0;
}