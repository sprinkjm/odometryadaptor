#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "odometryadaptor";

// For Block odometryadaptor/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_odometryadaptor_geometry_msgs_Twist> Sub_odometryadaptor_1;

// For Block odometryadaptor/Subscribe1
SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_odometryadaptor_nav_msgs_Odometry> Sub_odometryadaptor_88;

// For Block odometryadaptor/Publish
SimulinkPublisher<nav_msgs::Odometry, SL_Bus_odometryadaptor_nav_msgs_Odometry> Pub_odometryadaptor_79;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

