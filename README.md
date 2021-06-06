# RoboticsND-Home-Service-Robot
Fifth project of the Robotics Software Engineer Nanodegree.

# Packages and first steps


First of all, an upgrade of the system is needed.

```
sudo apt-get update && apt-get upgrade
```

Since shell scripts will be used, xterm package must be installed.


```
sudo apt-get install xterm
```

The following Official ROS packages that will be used and must be installed.

1. Slam gmapping: With this package we can create a 2D grid map using laser and pose data provided by the robot.
```
git clone https://github.com/ros-perception/slam_gmapping.git 
```
2. Turtlebot_teleop: This package allows us to teleoperate the robot through the keyboard.
```
git clone  https://github.com/turtlebot/turtlebot.git 
```
3. Turtlebot_rviz_launchers: This package runs a preconfigured rviz workspace every time we launch the simulations, saving us time in its configuration. 
```
git clone  https://github.com/turtlebot/turtlebot_interactions.git
```
4. Turtlebot simulator: It deploys a turtlebot in the gazebo chosen.
```
git clone https://github.com/turtlebot/turtlebot_simulator.git
```

Finally we have the packages that will be created throughout the project or that are necessary for its achievement.

1. Pick objects: This package allows to send navigation goals to the robot and carry out the tasks of the project.
2. Add markers: This package allows us to easily display primitive objects such as arrows, boxes, spheres, and lines in rviz, so that we can perform the task of simulating the picking up and delivery of a virtual package.
3. Pgm map creator: It allows to create a binay occupancy grid. Although it is not used directly in this project, it may become necessary when making any change to our environment.
4. RVIZ: Widely used throughout the projects, rviz is a 3D visualizer for the ROS.

# Home Service Robot 
The last test of all is intended to simulate the collection and delivery of a fictitious package. Initially, a marker must be displayed in the pickup zone waiting to be picked up. Once the robot reaches its position, its collection must be simulated by making the package disappear and wait 5 seconds to carry out the task. Later the robot must go to the delivery area where it will deposit the package.
