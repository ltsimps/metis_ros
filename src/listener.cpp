/**
 *  @file      listener.cpp
 *  @brief     Node implementation for Listerner
 *  @author    Lamar Simpson  
 * Copyright    2017 
 * MIT LICENSE
 */


#include "ros/ros.h"
#include "std_msgs/String.h"
#include "tf/transform_listener.h"
#include <sstream>
#include <string>
#include <iostream>
#include "metis_ros/strings.h"


struct buffer{
std::stringstream ss;
       

}message;
/**
*@brief handles messages for the chatter topic.
*@param std_msgs::stringConstPtr& msg
*/
void chatterCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("voice i  heard was: [%s]", msg->data.c_str());
}

void voiceCallback(const std_msgs::String::ConstPtr& msg) {
    std::string test = msg->data.c_str();
    //ROS_INFO("I heard: [%s]", msg->data.c_str());
    message.ss << msg->data<< " ";
    ROS_INFO("Message size  greater: [%lu]", message.ss.str().size());
    if(message.ss.str().size() > 100) {
     ROS_INFO("Current Message: [%s]", message.ss.str().c_str() );
     //ROS_INFO("Message size  greater: [%d]", message.ss.str().size());
      ros::NodeHandle v;
     int score = 0; 
     metis_ros::strings srv;
     ros::ServiceClient client = v.serviceClient<metis_ros::strings >("negative_output");
     srv.request.input = message.ss.str();
     client.call(srv);
     ROS_INFO("Score: [%i]", score);
    }

}
/**
*@brief main funtion for the listner  node
*@param int argc 
*@param char **argv
*/
int main(int argc, char **argv) {
    ros::init(argc, argv, "listener");

    ros::NodeHandle n;
    
    //ros::Subscriber sub = v.subscribe("chatter", 1000, chatterCallback);
    ros::Subscriber voice_sub = n.subscribe("voice_chatter", 1000, voiceCallback);
    

    ros::spin();

    return 0;
}
