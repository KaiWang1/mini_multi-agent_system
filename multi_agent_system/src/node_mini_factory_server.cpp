#include "ros/ros.h"
#include "std_msgs/String.h"
#include "multi_agent_system/node_mini_factory_server.h"

node_mini_factory_server_def::node_mini_factory_server_def()
{
	feedback_sub = n.subscribe("/agent_feedback",10,&node_mini_factory_server_def::agent_feedback_callback,this);
	task_1_client = n.serviceClient<multi_agent_system::agent_task_1>("/agent_task_1");
	task_2_client = n.serviceClient<multi_agent_system::agent_task_2>("/agent_task_2");

}
node_mini_factory_server_def::~node_mini_factory_server_def()
{

}
void node_mini_factory_server_def::agent_feedback_callback(const multi_agent_system::agent_feedback::ConstPtr& msg)
{
	ROS_INFO("RECEIVE A MESSAGE!");
}
bool node_mini_factory_server::task_1_client()
{
	if(task_1_client.call(task_1_srv)){
		ROS_INFO("SUCCESSED TO CALL SERVICE_TASK_1");
	}
	else{
		ROS_INFO("FAILED TO CALL SERVICE_TASK_1");
		return false;
	}
	return true;
}
bool node_mini_factory_server::task_2_client()
{
	if(task_2_client.call(task_2_srv)){
		ROS_INFO("SUCCESSED TO CALL SERVICE_TASK_2");
	}
	else{
		ROS_INFO("FAILED TO CALL SERVICE_TASK_2");
		return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	ros::init(argc, argv, "node_mini_factory_server");
	node_mini_factory_server_def node_mini_factory_server;
	ros::spin();

	return 0;
}