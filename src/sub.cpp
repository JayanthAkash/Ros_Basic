#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
#include <iostream>
#include <sstream>

void number_callback(const std_msgs::Int32::ConstPtr& msg) 
{
ROS_INFO("Received [%d]",msg->data);
}

void welcome_callback(const std_msgs::String::ConstPtr& msg1) 
{
ROS_INFO("Received [%s]",msg1->data.c_str());
}

int main(int argc ,char ** argv)
{
    ros::init(argc,argv, "lec1_topic_subscriber");
    ros::NodeHandle node_obj;
    ros::Subscriber name_subscriber = node_obj.subscribe("/numbers",10,number_callback); // the same topic name
    ros::Subscriber welcome_subscriber = node_obj.subscribe("/welcome",10,welcome_callback);
    ros::spin();
    return 0;
}
