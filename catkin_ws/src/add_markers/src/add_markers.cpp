#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>



double X_PickUp = 1.0, Y_PickUp=1.0,OW_PickUp=1.0;
double X_DropOff = -5.5, Y_DropOff=3.0, OW_DropOff=1.0;

double DistanceToPU = 100.0;
double DistanceToDO = 100.0;

double DistanceThreshold = 0.2;

int PickUp = 0;
int DropOff = 0;

void odom_callback (const nav_msgs::Odometry::ConstPtr& msg){
  double x = msg->pose.pose.position.x;
  double y = msg->pose.pose.position.y;


  DistanceToPU = sqrt(pow(X_PickUp - x,2)  + pow(Y_PickUp - y,2));
  DistanceToDO = sqrt(pow(X_DropOff - x,2)  + pow(Y_DropOff - y,2));

  if(DistanceToPU <= DistanceThreshold){
    PickUp = 1;
  }  else if (DistanceToDO <= DistanceThreshold ){
    DropOff = 1;
  }
}


int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

  visualization_msgs::Marker marker;
  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  marker.header.frame_id = "/map";
  marker.header.stamp = ros::Time::now();

  // Set the namespace and id for this marker.  This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one
  marker.ns = "add_markers";
  marker.id = 0;

  // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
  marker.type = shape;

  // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
  marker.action = visualization_msgs::Marker::ADD;

  // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
  marker.pose.position.x = X_PickUp;
  marker.pose.position.y = Y_PickUp;
  marker.pose.position.z = 0.0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = OW_PickUp;

  // Set the scale of the marker -- 1x1x1 here means 1m on a side
  marker.scale.x = 0.2;
  marker.scale.y = 0.2;
  marker.scale.z = 0.2;

  // Set the color -- be sure to set alpha to something non-zero!
  marker.color.r = 0.0f;
  marker.color.g = 1.0f;
  marker.color.b = 0.0f;
  marker.color.a = 1.0;

  marker.lifetime = ros::Duration();

  // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
    
  marker_pub.publish(marker);

  // Subscribe to odom
  ros::Subscriber sub = n.subscribe("odom", 100, odom_callback);
  

  while (ros::ok())
  {

    if (PickUp == 1 && DropOff == 0){

      marker.action = visualization_msgs::Marker::DELETE;
      marker_pub.publish(marker);    
      
    }else if(DropOff == 1 && PickUp == 1){

      marker.action = visualization_msgs::Marker::ADD;
      marker.pose.position.x = X_DropOff;
      marker.pose.position.y = Y_DropOff;
      marker.pose.orientation.w = OW_DropOff;
      marker_pub.publish(marker);
    }

    ros::Duration(0.5).sleep();
    ros::spinOnce();
  }

  return 0;




}
