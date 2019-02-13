#include "ros/ros.h"
#include "std_msgs/String.h"
#include "multi_agent_system/node_robot_1.h"

robot_1_def::robot_1_def()
{
	task_1_server = n.advertiseService("/agent_task_1",&robot_1_def::task_1_function,this);
}
robot_1_def::~robot_1_def()
{

}
bool robot_1_def::task_1_function(multi_agent_system::agent_task_1::Request &req,multi_agent_system::agent_task_1::Response &res)
{
	ROS_INFO("TASK1 IS CALLED!");
	return true;
}

int main(int argc, char *argv[])
{
	ros::init(argc, argv, "node_robot_1");
	robot_1_def robot_1;
	ros::spin();
	return 0;
}