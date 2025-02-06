#include<ros/ros.h>

int main(int argc,char *argv[])
{
    ros::init(argc,argv,"chao_node");
    printf("我的枪去而复返，你的生命有去无回!\n");
    while(ros::ok())
    {
        printf("别投，我还能秀!\n");

    }
    return 0;
}