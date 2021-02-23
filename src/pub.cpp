#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char **argv)
{

ros::init(argc, argv,"lec1_topic_publisher");// creating a unique name for the node
ros::NodeHandle node_obj;// enabling the node 

ros::Publisher number_publisher =
node_obj.advertise<std_msgs::Int32>("/numbers",10);// | 1 |  2 |  3  |  .......|10|

ros::Publisher welcome_publisher =
node_obj.advertise<std_msgs::String>("/welcome",10);


ros::Rate loop_rate(10);
int number_count = 0;

while (ros::ok()) // shutdown ctrl + c 
{
    std_msgs::Int32 msg;
    std_msgs::String msg1;
    std::stringstream ss;

    ss << "Welcome to ROS Bootcamp" << number_count;

    
    msg.data = number_count;
    msg1.data = ss.str();
    
    

    ROS_INFO("%d",msg.data);
    ROS_INFO("%s", msg1.data.c_str());

    number_publisher.publish(msg);
    welcome_publisher.publish(msg1);

    ros::spinOnce(); //this is must to run everytime
    loop_rate.sleep();
    ++number_count;

}

return 0;
}
