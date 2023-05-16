#include "ros/ros.h"


#include "tf2_ros/static_transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

int main(int argc, char* argv[]) {
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"static_brocast");

    tf2_ros::StaticTransformBroadcaster broadcaster;  // 创建静态坐标转换广播器

    geometry_msgs::TransformStamped tfs;  // 创建坐标系信息

    tfs.header.seq = 100;
    tfs.header.stamp = ros::Time::now();
    tfs.header.frame_id = "base_link";
    tfs.child_frame_id = "laser";
    tfs.transform.translation.x = 0.2;
    tfs.transform.translation.y = 0.0;
    tfs.transform.translation.z = 0.5;
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,0);
    tfs.transform.rotation.x = qtn.getX();
    tfs.transform.rotation.y = qtn.getY();
    tfs.transform.rotation.z = qtn.getZ();
    tfs.transform.rotation.w = qtn.getW();

    broadcaster.sendTransform(tfs);

    ros::spin();


    return 0;
}

