#!/usr/bin/env python3
import rospy
import tf
import math

import tf.transformations


def tf_transform():
    # ��ʼ��ROS�ڵ�
    rospy.init_node("tf_transform", anonymous=False)
    # ����TF�㲥��
    tf_broadcaster = tf.TransformBroadcaster()
    # ����ѭ��Ƶ��Ϊ10Hz
    rate = rospy.Rate(10)
    # ���ó�ʼ�Ƕ�Ϊ0
    angle = 0
    # ��ӡ��ʼ��Ϣ
    rospy.loginfo("Start TF Transform")
    while not rospy.is_shutdown():
        # ��ȡ��ǰʱ��
        current_time = rospy.Time.now()
        # ����x, y����
        x = math.cos(angle) * 0.3
        y = math.sin(angle) * 0.3
        # ����z����
        z = 0.2
        # ������Ԫ��
        quat = tf.transformations.quaternion_from_euler(0, 0, angle)
        # �㲥TF�任
        tf_broadcaster.sendTransform((x, y, z), quat, current_time, "tf3", "tf1")
        # �㲥��һ��TF�任
        tf_broadcaster.sendTransform(
            (x, y, z * 2), (0, 0, 0, 1), current_time, "tf4", "tf1"
        )
        # ���ӽǶ�
        angle += 0.1
        # ����Ƶ������
        rate.sleep()


if __name__ == "__main__":
    tf_transform()
