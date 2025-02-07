#include<ros/ros.h>
#include<std_msgs/String.h>

int main(int argc,char *argv[])
{
    ros::init(argc,argv,"yao_node");
    printf("过去生于未来！\n");

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("ge_ge_dai_wo",10);

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        printf("我要开始刷屏了!\n");
        std_msgs::String msg;
        msg.data="求上车++++";
        pub.publish(msg);
        loop_rate.sleep();
    }
    return 0;
}
