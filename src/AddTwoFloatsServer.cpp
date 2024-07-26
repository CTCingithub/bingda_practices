#include "ros/ros.h"
#include "bingda_practices/AddTwoFloats.h"

bool add(bingda_practices::AddTwoFloats::Request &req,
         bingda_practices::AddTwoFloats::Response &res)
{
    // 将请求中的两个浮点数相加，并将结果赋值给响应中的sum
    res.sum = req.a + req.b;
    // 打印请求中的两个浮点数
    ROS_INFO("request: x=%f, y=%f", (float)req.a, (float)req.b);
    // 打印响应中的和
    ROS_INFO("sending back response: [%f]", (float)res.sum);
    // 返回true
    return true;
}

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "add_two_floats_server");
    ros::NodeHandle n;

    // 注册服务
    ros::ServiceServer service = n.advertiseService("add_two_floats", add);
    ROS_INFO("Ready to add two floats.");
    ros::spin();

    return 0;
}