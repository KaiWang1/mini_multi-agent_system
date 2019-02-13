#include "ros/ros.h"
#include "std_msgs/String.h"

robot_2_def::robot_2_def()
{
	task_2_server = n.advertiseService("/agent_task_2",&robot_2_def::task_2_function,this);
}
robot_2_def::~robot_2_def()
{

}
bool robot_2_def::task_2_function(multi_agent_system::agent_task_2::Request &req,multi_agent_system::agent_task_2::Response &res)
{
	ROS_INFO("TASK2 IS CALLED!");
	return true;
}
int main(int argc, char *argv[])
{
	ros::init(argc, argv, "node_robot_2");
	robot_2_def robot_2;
	ros::spin();
	return 0;
}