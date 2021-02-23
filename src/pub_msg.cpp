
#include "ros/ros.h"
#include "lec1/demo_msg.h"
#include <iostream>

int main(int argc, char **argv)
{

ros::init(argc, argv,"lec1_topic_publisher");
ros::NodeHandle node_obj;

ros::Publisher number_publisher =
node_obj.advertise<lec1::demo_msg>("/numbers",10);


ros::Rate loop_rate(10);
int number_count = 0;

while (ros::ok())
{
    lec1::demo_msg msg;
    msg.number = number_count;
   

    ROS_INFO("%d",msg.number);
    number_publisher.publish(msg);
    

    ros::spinOnce();
    loop_rate.sleep();
    ++number_count;

}

return 0;
}
