#!/bin/sh

# launch turtlebot_world.launch file to deploy a turtlebot in you environment
export ROBOT_INITIAL_POSE='-x 0 -y 0 -z 0 -R 0 -P 0 -Y 1.57';
xterm  -e  "roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(pwd)/../../src/map/pizzeria.world " &
sleep 15

# The gmapping_demo.launch or run slam_gmapping to perform slam
xterm  -e  " roslaunch turtlebot_gazebo amcl_demo.launch  map_file:=$(pwd)/../../src/map/pizzeria.yaml " &
sleep 15

# The view_navigation.launch to observe the map in rviz
xterm  -e  " roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 10

# Add markers
xterm -e " rosrun add_markers add_markers" &
sleep 5

# Pick objects
xterm -e  " rosrun pick_objects pick_objects" 
