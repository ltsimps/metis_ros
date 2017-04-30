#include <ros/ros.h>
#include <ros/service_client.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <gtest/gtest.h>
#include <ros/service_client.h>
#include "beginner_tutorials/strings.h"




//test the strings service existence
TEST(TalkeSuite, existence_Test) {
  ros::NodeHandle nh; 
  ros::ServiceClient client;

  
  //call service and check for existence
  client = nh.serviceClient < beginner_tutorials::strings > ("change_output");
  bool exists(client.waitForExistence(ros::Duration(20)));
  EXPECT_TRUE(exists);

}




//http://docs.ros.org/api/tf/html/c++/classtf_1_1Transformer.html Transformer api
TEST(TestSuite, tf_test) {

  //ros::NodeHandle n;
  tf::TransformListener listener;
  tf::StampedTransform transform;

  //needed to make sure the transform is available, otherwise garbage will be in the transform values
  listener.waitForTransform("world", "talk", ros::Time(0), ros::Duration(20.0) );
  listener.lookupTransform("world", "talk", ros::Time(0), transform);


    EXPECT_EQ(1, transform.getOrigin().x());
    EXPECT_EQ(1, transform.getOrigin().y());
    EXPECT_EQ(1, transform.getOrigin().z());

    //Test transform after rotation with transform.setRotation(tf::Quaternion(0, 1, 0, 1));
 
    EXPECT_EQ(0, transform.getRotation().x());
    EXPECT_LT(0, transform.getRotation().y());
    EXPECT_EQ(0, transform.getRotation().z());
    EXPECT_LT(0, transform.getRotation().w());
    EXPECT_LT(transform.getRotation().w(), 0.8);
    EXPECT_LT(transform.getRotation().w(), 0.8);

}



int main(int argc, char **argv) {

  ros::init(argc, argv, "talker_test");

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
