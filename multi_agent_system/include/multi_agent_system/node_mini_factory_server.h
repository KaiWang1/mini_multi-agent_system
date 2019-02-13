#pragma once
#include "ros/ros.h"
#include "multi_agent_system/agent_feedback.h"
class node_mini_factory_server_def{
public:
    node_mini_factory_server_def();
    ~node_mini_factory_server_def();

    void agent_feedback_callback(const multi_agent_system::agent_feedback::ConstPtr& msg);
private:
    ros::NodeHandle n;
    ros::Subscriber feedback_sub;
};