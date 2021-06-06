#!/bin/sh

# launch turtlebot_world.launch file to deploy a turtlebot in you environment
xterm  -e  "roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(pwd)/../../src/map/pizzeria.world " &
sleep 10

# The gmapping_demo.launch or run slam_gmapping to perform slam
xterm  -e  " roslaunch turtlebot_gazebo gmapping_demo.launch " &
sleep 10

# The view_navigation.launch to observe the map in rviz
xterm  -e  "roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 10

# The keyboard_teleop.launch to manually control the robot with keyboard commands
xterm  -e  "roslaunch turtlebot_teleop keyboard_teleop.launch" &
sleep 10
