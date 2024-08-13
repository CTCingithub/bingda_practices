#!/usr/bin/env python3
import rospy
import tf
import math

import tf.transformations


def tf_transform():
    # 初始化ROS节点
    rospy.init_node("tf_transform", anonymous=False)
    # 创建TF广播器
    tf_broadcaster = tf.TransformBroadcaster()
    # 设置循环频率为10Hz
    rate = rospy.Rate(10)
    # 设置初始角度为0
    angle = 0
    # 打印开始信息
    rospy.loginfo("Start TF Transform")
    while not rospy.is_shutdown():
        # 获取当前时间
        current_time = rospy.Time.now()
        # 计算x, y坐标
        x = math.cos(angle) * 0.3
        y = math.sin(angle) * 0.3
        # 设置z坐标
        z = 0.2
        # 计算四元数
        quat = tf.transformations.quaternion_from_euler(0, 0, angle)
        # 广播TF变换
        tf_broadcaster.sendTransform((x, y, z), quat, current_time, "tf3", "tf1")
        # 广播另一个TF变换
        tf_broadcaster.sendTransform(
            (x, y, z * 2), (0, 0, 0, 1), current_time, "tf4", "tf1"
        )
        # 增加角度
        angle += 0.1
        # 按照频率休眠
        rate.sleep()


if __name__ == "__main__":
    tf_transform()
