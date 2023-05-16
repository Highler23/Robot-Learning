# ROS常用指令

## 话题

> rostopic list  显示所有活动状态下的主题

```shell
rostopic list -v   # 列出所有话题
```

> rostopic info # 显示指定主题相关信息

```shell
rosmsg info geometry_msgs/TransformStamped # 查看话题 geometry_msgs/TransformStamped 详细信息
	std_msgs/Header header
  		uint32 seq
  		time stamp
      	       string frame_id
	string child_frame_id
	geometry_msgs/Transform transform
      		geometry_msgs/Vector3 translation
    			float64 x
   			         float64 y
    			float64 z
  	    geometry_msgs/Quaternion rotation
    		float64 x
    		float64 y
    		float64 z
    		float64 w
```

