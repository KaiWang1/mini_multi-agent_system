#include "ros/ros.h"
#include "std_msgs/String.h"
#include "multi_agent_system/node_mini_factory_server.h"

node_mini_factory_server_def::node_mini_factory_server_def()
{
	feedback_sub = n.subscribe("/agent_feedback",10,&node_mini_factory_server_def::agent_feedback_callback,this);
}
node_mini_factory_server_def::~node_mini_factory_server_def()
{

}
void node_mini_factory_server_def::agent_feedback_callback(const multi_agent_system::agent_feedback::ConstPtr& msg)
{
	ROS_INFO("RECEIVE A MESSAGE!");
}

int main(int argc, char *argv[])
{
	ros::init(argc, argv, "node_mini_factory_server");
	node_mini_factory_server_def node_mini_factory_server;
	ros::spin();

	return 0;
}