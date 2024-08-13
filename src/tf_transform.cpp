#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>

int main(int argc, char **argv)
{
    // ��ʼ��ROS�ڵ�
    ros::init(argc, argv, "tf_transform");
    // �����ڵ���
    ros::NodeHandle n;
    // ���巢��Ƶ��
    ros::Rate r(10);
    // �����㲥��
    tf::TransformBroadcaster broadcaster;
    // ����Ƕȱ���
    float angle = 0.0;
    // �����������
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
    // �����ʾ��Ϣ
    ROS_INFO("Start TF Transform");
    // ���ڵ���������ʱ
    while (n.ok())
    {
        // ��������
        x = cos(angle) * 0.3;
        y = sin(angle) * 0.3;
        z = 0.2;
        // ���ͱ任����
        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(tf::createQuaternionFromRPY(0, 0, angle), tf::Vector3(x, y, z)),
                ros::Time::now(), "tf1", "tf3"));
        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(x, y, z * 2)),
                ros::Time::now(), "tf1", "tf4"));
        // ����Ƶ������
        r.sleep();
        // �Ƕȱ�������
        angle += 0.01;
    }
}