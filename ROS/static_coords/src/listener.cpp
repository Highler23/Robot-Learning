#include "ros/ros.h"


#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"  // 转换坐标时使用


int main(int argc, char* argv[]) {
    setlocale(LC_ALL,"");  
    ros::init(argc,argv,"static_sub");  
    ros::NodeHandle nh;

    tf2_ros::Buffer buffer;  // 创建一个buffer缓存
    tf2_ros::TransformListener listener(buffer);  // 创建订阅对象
    
    geometry_msgs::PointStamped point_laser;  // 创建坐标点数据(这里写死，实际应用中动态生成)
        point_laser.header.frame_id = "laser";
        point_laser.header.stamp = ros::Time::now();
        point_laser.point.x = 2.0;
        point_laser.point.y = 3.0;
        point_laser.point.z = 5.0;
    
    ros::Rate rate(1);  // 设置循环频率
    while (ros::ok()) {
        try {
            // buffer.transform()第一个参数为待转换的坐标点；第二个参数为转换后坐标点的坐标系
            geometry_msgs::PointStamped point_base = buffer.transform(point_laser,"base_link");
            ROS_INFO("转换后的数据: (%.2f,%.2f,%.2f),参考的坐标是: (%.2f,%.2f,%.2f)",
                    point_base.point.x,point_base.point.y,point_base.point.z,
                    point_laser.point.x,point_laser.point.y,point_laser.point.z);
        }
        catch(const std::exception& e) {
            // std::cerr << e.what() << '\n';
            ROS_INFO("程序异常......");
        }
        rate.sleep();
        ros::spinOnce();
    }
    


    return 0;
}

