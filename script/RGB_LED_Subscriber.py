#!/usr/bin/env python3
import rospy
from bingda_practices.msg import RGB_LED


def callback(data):
    loginfo = (
        str(data.ID)
        + " "
        + str(data.RGB[0])
        + " "
        + str(data.RGB[1])
        + " "
        + str(data.RGB[2])
        + " "
        + str(data.Others[0])
        + " "
        + str(data.Others[1])
    )
    rospy.loginfo(loginfo)


def RGB_LED_Subscriber():
    rospy.init_node("RGB_LED_Subscriber_Python", anonymous=True)
    rospy.loginfo("RGB_LED_Subscriber_Python node has been started")
    rospy.Subscriber("RGB_LED", RGB_LED, callback)
    rospy.spin()


if __name__ == "__main__":
    RGB_LED_Subscriber()
