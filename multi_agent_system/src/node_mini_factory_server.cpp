#include "ros/ros.h"
#include "std_msgs/String.h"
#include "multi_agent_system/node_mini_factory_server.h"

node_mini_factory_server_def::node_mini_factory_server_def():task_ID(0),sleep_count(0)
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
	//ROS_INFO("RECEIVE A MESSAGE!");
	bool temp_add = true;
	for(auto &temp:robot_list){
		temp_add = true;
		if(temp.robot_id == msg->robot_id){
			temp_add = false;
			temp.robot_state = msg->robot_state;
			break;
		}	
	}
	if(temp_add){
		robot_def temp_robot;
		temp_robot.robot_id = msg->robot_id;
		temp_robot.robot_state = msg->robot_state;
		temp_robot.task_done = false;
		robot_list.push_back(temp_robot);
	}

}
bool node_mini_factory_server_def::task_1_client_function(unsigned int id_value)
{
	task_1_srv.request.ID = id_value;
	task_1_srv.request.cmd = "executing";
	task_1_srv.response.robot_state = "none";
	if(task_1_client.call(task_1_srv)){
		if(task_1_srv.response.robot_state == "executing"){
			ROS_INFO("SUCCESSED TO CALL SERVICE_TASK_1");
		}
		else{
			ROS_WARN("FAILED TO CALL SERVICE_TASK_1");
			return false;
		}
	}
	else{
		ROS_WARN("FAILED TO CALL SERVICE_TASK_1");
		return false;
	}
	return true;
}
bool node_mini_factory_server_def::task_2_client_function(unsigned int id_value)
{
	task_2_srv.request.ID = id_value;
	task_2_srv.request.cmd = "executing";
	task_2_srv.response.robot_state = "none";
	if(task_2_client.call(task_2_srv)){
		if(task_2_srv.response.robot_state == "executing"){
			ROS_INFO("SUCCESSED TO CALL SERVICE_TASK_2");
		}
		else{
			ROS_WARN("FAILED TO CALL SERVICE_TASK_2");
			return false;
		}		
	}
	else{
		ROS_WARN("FAILED TO CALL SERVICE_TASK_2");
		return false;
	}
	return true;
}
void node_mini_factory_server_def::task_function()
{
	bool temp_all_done = true;
	for(auto &temp_robot:robot_list){
		if(!temp_robot.task_done ){
			if(temp_robot.robot_state == "ready"){
				switch(temp_robot.robot_id){
					case 1:
					if(task_1_client_function(task_ID)){
						temp_robot.task_done = true;
						temp_robot.robot_state = task_1_srv.response.robot_state;
					}
					break;
					case 2:
					if(task_2_client_function(task_ID)){
						temp_robot.task_done = true;
						temp_robot.robot_state = task_2_srv.response.robot_state;
					}
					break;
					default:
					ROS_WARN("unkown robot");
					break;
				}
			}
		if(!temp_robot.task_done)
			temp_all_done = false;	
		}
	}
	if(temp_all_done){
		task_ID++;
		for(auto &temp_robot:robot_list){
			temp_robot.task_done = false;
			//temp_robot.robot_state = "none";
		}
	}
}
void node_mini_factory_server_def::run()
{
	switch(task_ID){
		case 0:
		//sleep(2000);
		sleep_count++;
		if(sleep_count >= 500) //5s
			task_ID++;
		break;
		case 1:
		task_function();
		break;
		case 2:
		task_function();
		break;
		case 3:
		task_function();
		break;
		case 4:
		task_function();
		break;
		case 5:
		task_function();
		break;
		default:
		ros::shutdown();
		break;
	}
	ROS_INFO_THROTTLE(1.0,"TASK_ID:%d",task_ID);
}

int main(int argc, char *argv[])
{
	ros::init(argc, argv, "node_mini_factory_server");
	node_mini_factory_server_def node_mini_factory_server;
	ros::Rate loop_rate(100);
	while(ros::ok()){
		node_mini_factory_server.run();
		loop_rate.sleep();
		ros::spinOnce();
	}
	

	return 0;
}