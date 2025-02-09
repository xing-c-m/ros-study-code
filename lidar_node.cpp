#include<ros/ros.h>
#include<sensor_msgs/LaserScan.h>

void LidarCallback(const sensor_msgs::LaserScan msg)
{
    float fMidDist = msg.ranges[180];
    ROS_INFO("前方测距ranges[180] = %f米",fMidDist);
}

int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"lidar_node");

    ros::NodeHandle n;
    ros::Subscriber linar_sub = n.subscribe("/scan",10,&LidarCallback);

    ros::spin();

    return 0;
}