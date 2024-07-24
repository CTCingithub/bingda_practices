#include "ros/ros.h"
#include "bingda_practices/RGB_LED.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "RGB_LED_Publisher"); // ��ʼ��ROS�ڵ�
    ros::NodeHandle n; // �����ڵ���
    ros::Publisher RGB_LED_Publisher = n.advertise<bingda_practices::RGB_LED>("rgb_led", 10); // ����rgb_led����
    ros::Rate loop_rate(10); // ����ѭ��Ƶ��Ϊ10Hz

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