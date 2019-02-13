#pragma once
#include "ros/ros.h"
#include "multi_agent_system/agent_feedback.h"
#include "multi_agent_system/agent_task_1.h"
#include "multi_agent_system/agent_task_2.h"
#include <vector>

struct robot_def{
    unsigned int robot_id;
    std::string robot_state;
    bool task_done;
};
class node_mini_factory_server_def{
public:
    node_mini_factory_server_def();
    ~node_mini_factory_server_def();

    void agent_feedback_callback(const multi_agent_system::agent_feedback::ConstPtr& msg);
    bool task_1_client_function(unsigned int id_value);
    bool task_2_client_function(unsigned int id_value);
    void run();
    void task_function();
private:
    ros::NodeHandle n;
    ros::Subscriber feedback_sub;
    ros::ServiceClient task_1_client,task_2_client;
    multi_agent_system::agent_task_1 task_1_srv;
    multi_agent_system::agent_task_2 task_2_srv;
    unsigned int task_ID,sleep_count;
    std::vector<robot_def> robot_list;
};