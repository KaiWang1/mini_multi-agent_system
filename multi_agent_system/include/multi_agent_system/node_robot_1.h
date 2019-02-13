#pragma once
#include "ros/ros.h"
#include "multi_agent_system/agent_task_1.h"
#include "multi_agent_system/agent_feedback.h"

#define robot_clock 0.1
#define robot_task_cost 5
#define robot_timer_count_limit 1.0/robot_clock*robot_task_cost
enum robot_state
{
    ready,
    executing
};

class robot_1_def{
public:
    robot_1_def();
    ~robot_1_def();
    bool task_1_function(multi_agent_system::agent_task_1::Request &req,multi_agent_system::agent_task_1::Response &res);
private:
    ros::NodeHandle n;
    ros::ServiceServer task_1_server;
    ros::Timer robot_timer;
    ros::Publisher agent_pub;
    robot_state robot_1_state;
    unsigned int timer_count;

    void time_callback(const ros::TimerEvent&);
};
