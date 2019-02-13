#include "ros/ros.h"
#include "std_msgs/String.h"
#include "multi_agent_system/node_robot_2.h"

robot_2_def::robot_2_def()
{
	task_2_server = n.advertiseService("/agent_task_2",&robot_2_def::task_2_function,this);
	robot_timer = n.createTimer(ros::Duration(robot_clock), &robot_2_def::time_callback,this);
}
robot_2_def::~robot_2_def()
{

}
bool robot_2_def::task_2_function(multi_agent_system::agent_task_2::Request &req,multi_agent_system::agent_task_2::Response &res)
{
	ROS_INFO("TASK2 IS CALLED! CLIENT ID=%d",req.ID);
	if(req.cmd == "executing"){
		robot_2_state = executing;
		res.robot_state = "executing";
	}
	else
		res.robot_state = "error";
	return true;
}
void robot_2_def::time_callback(const ros::TimerEvent&)
{
	if(robot_2_state == executing){
		timer_count++;
		if(timer_count >= robot_timer_count_limit){
			robot_2_state = ready;
			timer_count = 0;
		}
	}
	else
		timer_count = 0;
}

int main(int argc, char *argv[])
{
	ros::init(argc, argv, "node_robot_2");
	robot_2_def robot_2;
	ros::spin();
	return 0;
}