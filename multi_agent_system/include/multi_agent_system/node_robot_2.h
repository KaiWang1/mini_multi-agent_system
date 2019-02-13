#pragma once
#include "ros/ros.h"
#include "multi_agent_system/agent_task_2.h"

class robot_2_def{
public:
    robot_2_def();
    ~robot_2_def();
    bool task_2_function(multi_agent_system::agent_task_2::Request &req,multi_agent_system::agent_task_2::Response &res);
private:
    ros::NodeHandle n;
    ros::ServiceServer task_1_server;
};
