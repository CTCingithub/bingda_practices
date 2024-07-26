#include "ros/ros.h"
#include "bingda_practices/AddTwoFloats.h"

bool add(bingda_practices::AddTwoFloats::Request &req,
         bingda_practices::AddTwoFloats::Response &res)
{
    // �������е�������������ӣ����������ֵ����Ӧ�е�sum
    res.sum = req.a + req.b;
    // ��ӡ�����е�����������
    ROS_INFO("request: x=%f, y=%f", (float)req.a, (float)req.b);
    // ��ӡ��Ӧ�еĺ�
    ROS_INFO("sending back response: [%f]", (float)res.sum);
    // ����true
    return true;
}

int main(int argc, char **argv)
{
    // ��ʼ��ROS�ڵ�
    ros::init(argc, argv, "add_two_floats_server");
    ros::NodeHandle n;

    // ע�����
    ros::ServiceServer service = n.advertiseService("add_two_floats", add);
    ROS_INFO("Ready to add two floats.");
    ros::spin();

    return 0;
}