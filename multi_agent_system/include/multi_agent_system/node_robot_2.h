#pragma once
#include "ros/ros.h"
#include "multi_agent_system/agent_task_2.h"


#define robot_clock 0.1
#define robot_task_cost 3
#define robot_timer_count_limit 1.0/robot_clock*robot_task_cost
enum robot_state
{
    ready,
    executing
};
class robot_2_def{
public:
    robot_2_def();
    ~robot_2_def();
    bool task_2_function(multi_agent_system::agent_task_2::Request &req,multi_agent_system::agent_task_2::Response &res);
private:
    ros::NodeHandle n;
    ros::ServiceServer task_2_server;
    ros::Timer robot_timer;
    robot_state robot_2_state;
    unsigned int timer_count;

    void time_callback(const ros::TimerEvent&);
};
