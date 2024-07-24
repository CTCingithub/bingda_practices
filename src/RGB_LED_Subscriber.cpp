#include "ros/ros.h"
#include "bingda_practices/RGB_LED.h"
#include "std_msgs/String.h"

// Listener for the RGB LED topic
void RGB_LED_Callback(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("Received RGB_LED Message: ID = %d, RGB = (%d, %d, %d), Others = (%f, %f)",
             msg->ID, msg->RGB[0], msg->RGB[1], msg->RGB[2], msg->Others[0], msg->Others[1]);
}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "RGB_LED_Listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("RGB_LED", 1000, RGB_LED_Callback);
    ros::spin();
    return 0;
}
