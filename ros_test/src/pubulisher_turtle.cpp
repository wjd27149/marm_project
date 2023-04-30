#include"ros/ros.h"
#include"geometry_msgs/Twist.h"

int main(int argc, char *argv[])
{
        //设置编码
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"cmd_vel_control");

    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",1000);

    // msg.linear.x = 1.0;
    // msg.linear
    geometry_msgs::Twist msg;
    msg.linear.x = 1.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;

    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 2.0;    
        //4-2.设置发送频率
    ros::Rate r(10);
    //4-3.循环发送
    while (ros::ok())
    {
        pub.publish(msg);

        ros::spinOnce();
    }


    return 0;
}