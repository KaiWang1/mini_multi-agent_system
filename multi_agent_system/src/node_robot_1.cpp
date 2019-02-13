#include "ros/ros.h"
#include "std_msgs/String.h"
#include "multi_agent_system/node_robot_1.h"

robot_1_def::robot_1_def():robot_1_state(ready),timer_count(0)
{
	task_1_server = n.advertiseService("/agent_task_1",&robot_1_def::task_1_function,this);
	robot_timer = n.createTimer(ros::Duration(robot_clock), &robot_1_def::time_callback,this);
}
robot_1_def::~robot_1_def()
{

}
bool robot_1_def::task_1_function(multi_agent_system::agent_task_1::Request &req,multi_agent_system::agent_task_1::Response &res)
{
	ROS_INFO("TASK1 IS CALLED! CLIENT ID=%d",req.ID);
	if(req.cmd == "executing"){
		robot_1_state = executing;
		res.robot_state = "executing";
	}
	else
		res.robot_state = "error";
	return true;
}
void robot_1_def::time_callback(const ros::TimerEvent&)
{
	if(robot_1_state == executing){
		timer_count++;
		if(timer_count >= robot_timer_count_limit){
			robot_1_state = ready;
			timer_count = 0;
		}
	}
	else
		timer_count = 0;
}

int main(int argc, char *argv[])
{
	ros::init(argc, argv, "node_robot_1");
	robot_1_def robot_1;
	ros::spin();
	return 0;
}