#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "tf_transform");
    // 创建节点句柄
    ros::NodeHandle n;
    // 定义发布频率
    ros::Rate r(10);
    // 创建广播器
    tf::TransformBroadcaster broadcaster;
    // 定义角度变量
    float angle = 0.0;
    // 定义坐标变量
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
    // 输出提示信息
    ROS_INFO("Start TF Transform");
    // 当节点正常运行时
    while (n.ok())
    {
        // 计算坐标
        x = cos(angle) * 0.3;
        y = sin(angle) * 0.3;
        z = 0.2;
        // 发送变换矩阵
        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(tf::createQuaternionFromRPY(0, 0, angle), tf::Vector3(x, y, z)),
                ros::Time::now(), "tf1", "tf3"));
        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(x, y, z * 2)),
                ros::Time::now(), "tf1", "tf4"));
        // 按照频率休眠
        r.sleep();
        // 角度变量自增
        angle += 0.01;
    }
}