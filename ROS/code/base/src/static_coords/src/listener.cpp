#include "ros/ros.h"


#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"


int main(int argc, char* argv[]) {
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"tf_sub");
    ros::NodeHandle nh;

    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);
    



    return 0;
}

