#include "ros/ros.h"
#include "std_msgs/String.h"

void dogmsg(const std_msgs::String::ConstPtr& msg_p)
{
    ROS_INFO("i hear :%s",msg_p->data.c_str());
}

int main(int argc,char *argv[])
{
        //设置编码
    setlocale(LC_ALL,"");

    ros::init(argc , argv, "publish");

    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe<std_msgs::String>("chatter",10,dogmsg);

    ros::spin();

    return 0;
}