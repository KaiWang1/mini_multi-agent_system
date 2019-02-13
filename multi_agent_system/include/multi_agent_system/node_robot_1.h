#pragma once
#include "ros/ros.h"
#include "multi_agent_system/agent_task_1.h"

class robot_1_def{
public:
    robot_1_def();
    ~robot_1_def();
    bool task_1_function(multi_agent_system::agent_task_1::Request &req,multi_agent_system::agent_task_1::Response &res);
private:
    ros::NodeHandle n;
    ros::ServiceServer task_1_server;
};
