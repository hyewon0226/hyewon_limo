#include "ros/ros.h"
#include "std_msgs/String.h"

void subscriberCallback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("Recieved : %s\n", msg->data.c_str());
}

int main(int argc, char **argv){
    ros::init(argc, argv, "name_of_sub_node");
    ros::NodeHandle nh;

    ros::Subscriber i_am_the_subscribe = nh.subscribe("/name_of_topic", 100, subscriberCallback);

    ros::spin();

    return 0;

}