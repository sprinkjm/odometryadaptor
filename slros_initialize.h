#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block odometryadaptor/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_odometryadaptor_geometry_msgs_Twist> Sub_odometryadaptor_1;

// For Block odometryadaptor/Subscribe1
extern SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_odometryadaptor_nav_msgs_Odometry> Sub_odometryadaptor_88;

// For Block odometryadaptor/Publish
extern SimulinkPublisher<nav_msgs::Odometry, SL_Bus_odometryadaptor_nav_msgs_Odometry> Pub_odometryadaptor_79;

void slros_node_init(int argc, char** argv);

#endif
