#include<ros/ros.h>
#include<sensor_msgs/LaserScan.h>
#include<geometry_msgs/Twist.h>

ros::Publisher vel_pub;
int nCount = 0;

void LidarCallback(const sensor_msgs::LaserScan msg)
{
    float fMidDist = msg.ranges[180];
    ROS_INFO("前方测距ranges[180] = %f米",fMidDist);

    if(nCount>0)
    {
        nCount--;
        return;
    }

    geometry_msgs::Twist vel_cmd;
    if(fMidDist < 1.5)
    {
        vel_cmd.angular.z = 0.3;
        nCount = 50;
    }
    else
    {
        vel_cmd.linear.x = 0.05;
    }
    vel_pub.publish(vel_cmd);
}

int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"lidar_node");

    ros::NodeHandle n;
    ros::Subscriber linar_sub = n.subscribe("/scan",10,&LidarCallback);
    vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel",10);


    ros::spin();

    return 0;
}