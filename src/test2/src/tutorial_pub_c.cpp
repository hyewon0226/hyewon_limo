#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "name_of_pub_node");
    ros::NodeHandle nh;
    
    ros::Publisher i_am_the_publisher = nh.advertise<std_msgs::String>("name_of_topic", 100);

    ros::Rate loop_rate(5);

    int count = 0;

    while(ros::ok()){
        std_msgs::String testmsg;

        testmsg.data = std::to_string(count);
        ROS_INFO("value : %s\n", testmsg.data.c_str());

        i_am_the_publisher.publish(testmsg);

        ros::spinOnce();
        loop_rate.sleep();

        count++;
    }

    return 0;

}