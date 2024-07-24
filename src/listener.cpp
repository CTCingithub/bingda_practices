#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr &msg)
// This line defines the function chatterCallback, which takes a constant pointer to a std_msgs::String object as its parameter.
// The function is called when a message is received on the chatter topic.
{
    // Print out the message data to the console
    // The c_str() function is used to convert the std::string object to a C-style string.
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
    // ��ʼ��ROS�ڵ�
    ros::init(argc, argv, "listener");
    // �����ڵ���
    ros::NodeHandle n;
    // ��������chatter�������ûص�����chatterCallback�����д�СΪ1000
    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
    // ����ROSѭ��
    ros::spin();
    return 0;
}