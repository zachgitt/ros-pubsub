// ROS Default Header File
#include "ros/ros.h"

// MsgTutorial Message File Header
// The header file is automatically created when building the package. 
#include "ros_tutorials_topic/MsgTutorial.h"

int main(int argc, char **argv) // Node Main Function {

	ros::init(argc, argv, "topic_publisher"); // Initializes Node Name
	ros::NodeHandle nh; // Node handle declaration for communication with ROS system

	// Declare publisher, create publisher 'ros_tutorial_pub' using the 'MsgTutorial'
	// message file from the 'ros_tutorials_topic' package. The topic name is
	// 'ros_tutorial_msg' and the size of the publisher queue is set to 100. 
	ros::Publisher ros_tutorial_pub =
	nh.advertise<ros_tutorials_topic::MsgTutorial>("ros_tutorial_msg", 100);

	// Set the loop period. '10' refers to 10 Hz and the main loop repeats at 0.1 second intervals 
	// Declares message 'msg' in 'MsgTutorial' message file format
	// Variable to be used in message
	ros::Rate loop_rate(10);
	ros_tutorials_topic::MsgTutorial msg; 
	int count = 0;

	while (ros::ok())
	{
		msg.stamp = ros::Time::now(); // Save current time in the stamp of 'msg' 
		msg.data = count; // Save the the 'count' value in the data of 'msg'
		ROS_INFO("send msg = %d", msg.stamp.sec); // Print the 'stamp.sec' message
		ROS_INFO("send msg = %d", msg.stamp.nsec); // Print the 'stamp.nsec' message
		ROS_INFO("send msg = %d", msg.data);
		ros_tutorial_pub.publish(msg); loop_rate.sleep();
		++count;
	}

	return 0; 
}
