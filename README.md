# mini_multi-agent_system
1. 开发环境：
- ubuntu16.04；
- ros-kinetic;
2. 程序获取：在您的本地ros工作空间文件夹下的src文件夹中打开终端，运行如下命令：
```
git clone https://github.com/KaiWang1/mini_multi-agent_system.git
```
3. 编译：在您的本地ros工作空间文件夹下打开终端，运行如下命令：
```
catkin_make
```
4. 运行程序：在您的本地ros工作空间中打开终端，运行如下命令：
```
source devel/setup.bash
roslaunch multi_agent_system multi_agent_system.launch
```
5. 代码管理说明
- 远程仓库部署在github上，代码仓库地址为[https://github.com/KaiWang1/mini_multi-agent_system.git](https://github.com/KaiWang1/mini_multi-agent_system.git);
- 主分支为master分支，维护的开发分支为develop分支，所有开发过程中的feature分支和release分支均merge到master和develop分支后删除；
- 主分支master上按照需求说明上每一个步骤均打有tag标签：step1，step2,step3,step4,step5,step6,step7,step8,step9,step10；
6. 调试运行说明：
- 运行的三个节点：`node_mini_factory_server`、`node_robot_1`、`node_robot_2`；
- `node_mini_factory_server`订阅topic消息`/agent_feedback`，并维护了两个服务的客户端`/agent_task_1`和`/agent_task_2`；
- `node_robot_1`发布topic消息`/agent_feedback`，周期100ms，并发布了一个服务`/agent_task_1`；
- `node_robot_2`发布topic消息`/agent_feedback`，周期100ms，并发布了一个服务`/agent_task_2`；
- 终端打印消息说明：
    - `TASK_ID:0`为`node_mini_factory_server`节点产生，周期1秒，数字代表当前任务ID，任务ID=0,1,2,3,4,5。其中0代表空任务，持续时间5秒，5个任务结束后，程序自动关闭；
    - `TASK1 IS CALLED! CLIENT TASK_ID=1`为`node_robot_1`节点产生，数字代表任务ID，收到服务申请，并执行后产生；
    - `TASK2 IS CALLED! CLIENT TASK_ID=1`为`node_robot_2`节点产生，数字代表任务ID，收到服务申请，并执行后产生；
    - `SUCCESSED TO CALL SERVICE_TASK_1`和`SUCCESSED TO CALL SERVICE_TASK_2`为`node_mini_factory_server`节点产生，代表向`robot_1`和`robot_2`发送服务申请；
    - 其他消息参见程序。
- `node_mini_factory_server`节点会自动根据订阅的消息发现robot1和robot2，根据发现的robot和其状态，发送服务申请；
- `node_robot_1`任务执行时间5秒，`node_robot_2`任务执行时间3秒。
