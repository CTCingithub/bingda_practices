#!/usr/bin/env python3
import rospy
import os
from bingda_practices.msg import RGB_LED
from loguru import logger


def callback(data):
    logger.info(
        str(data.ID)
        + ","
        + str(data.RGB[0])
        + ","
        + str(data.RGB[1])
        + ","
        + str(data.RGB[2])
        + ","
        + str(data.Others[0])
        + ","
        + str(data.Others[1])
    )


def main():
    LogFileDir = (
        os.path.abspath(os.path.join(os.path.dirname(__file__), "..")) + "/log/"
    )
    rospy.init_node("RGB_LED_LogGen", anonymous=True)
    rospy.loginfo("RGB_LED_LogGen node has been started")
    rospy.loginfo(LogFileDir)

    logger.add(
        sink=LogFileDir + "RGB_LED.log",
        level="INFO",
        # compression="zip",
        encoding="utf-8",
        enqueue=True,
        format="{time:YYYY-MM-DD HH:mm:ss}|{message}",
    )
    rospy.Subscriber("RGB_LED", RGB_LED, callback)
    rospy.spin()


if __name__ == "__main__":
    main()
