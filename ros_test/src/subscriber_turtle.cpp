#include "ros/ros.h"
#include"turtlesim/Pose.h"

void dogmsg(const turtlesim::Pose::ConstPtr& msg_p)
{
    ROS_INFO("turtle pos is (%f ,%f) theta is %f   linear_v %f angular_v %f ",
                msg_p->x,msg_p->y,msg_p->theta,msg_p->linear_velocity,msg_p->angular_velocity);
}

int main(int argc,char *argv[])
{
        //设置编码
    setlocale(LC_ALL,"");

    ros::init(argc , argv, "subscriber_turtle");

    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe<turtlesim::Pose>("/turtle1/pose",10,dogmsg);

    ros::spin();

    return 0;
}