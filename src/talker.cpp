#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    // Initiate a ROS node named talker
    ros::init(argc, argv, "talker");

    // Create a handle for the node
    ros::NodeHandle n;

    // Create a topic publisher named chatter_pub, the topic's type is std_msgs::String
    // The topic is chatter. The cache queue's length is 1000
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    // The loop rate of publisher chatter_pub is 10Hz.
    ros::Rate loop_rate(10);

    // Count loop times
    int count = 10;

    // Run the following loop when ROS is working properly
    while (ros::ok())
    {
        // Create a std_msgs::String type variable named msg, to store message about to
        // publish
        std_msgs::String msg;

        // Create a stream of string to generate a string
        std::stringstream ss;
        ss << "Loop Time: " << count;

        // Pass string value to msg.data
        msg.data = ss.str();

        // Print the message to terminal with ROS_INFO
        ROS_INFO("%s", msg.data.c_str());

        // Publish the message to the topic
        chatter_pub.publish(msg);

        // The definition command ros::Rate loop_rate(10)
        // controls the rate of loop_rate.sleep() to be 10 Hz
        loop_rate.sleep();

        // Count publish times
        ++count;
    }
    return 0;
}