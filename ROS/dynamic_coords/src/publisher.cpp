#include "ros/ros.h"

#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"  // 和tf相关的发布订阅对象均封装在此处
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

void doPose(const turtlesim::Pose::ConstPtr& pose) {
    // 创建发布对象
    static tf2_ros::TransformBroadcaster pub;  // 定义成静态对象避免每次调用回调函数都创建发布对象
    // 组织待发布的消息
    geometry_msgs::TransformStamped tfs;
    tfs.header.frame_id = "world";
    tfs.header.stamp = ros::Time::now();
    tfs.child_frame_id = "turtle1";
    tfs.transform.translation.x = pose->x;
    tfs.transform.translation.y = pose->y;
    tfs.transform.translation.z = 0;
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,pose->theta);
    tfs.transform.rotation.x = qtn.getX();
    tfs.transform.rotation.y = qtn.getY();
    tfs.transform.rotation.z = qtn.getZ();
    tfs.transform.rotation.w = qtn.getW();
    // 发布消息
    pub.sendTransform(tfs);
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"dynamic_pub");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/turtle1/pose",100,doPose);
    ros::spin();

    return 0;
}
