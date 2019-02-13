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
