#include<ros/ros.h>
#include<std_msgs/String.h>

void chao_callback(std_msgs::String msg)
{
    ROS_INFO(msg.data.c_str());
    
}

void yao_callback(std_msgs::String msg)
{
    ROS_WARN(msg.data.c_str());
    
}

int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"ma_node");
    
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("kuai_shang_che_kai_hei_qun",10,chao_callback);
    ros::Subscriber sub_2 = nh.subscribe("ge_ge_dai_wo",10,yao_callback);

    while(ros::ok())
    {
        ros::spinOnce();
    }

    return 0;
}