#include "ros/ros.h"
#include "/home/liuyihan/catkin_ws/devel/include/ros_test/person.h"
#include "std_msgs/Header.h"
#include<sstream>
void doPerson(const ros_test::person::ConstPtr& person_p){
    ROS_INFO("订阅的人信息:%s, %d, %.2f  time is %s  id is %f",
     person_p->name.c_str(), person_p->age, person_p->height,person_p->stamp.toSec(),person_p->frame_id);
}

int main(int argc, char *argv[])
    {
        //设置编码
        setlocale(LC_ALL,"");

        ros::init(argc , argv, "subscriber_person");

        ros::NodeHandle nh;

        ros::Subscriber pub = nh.subscribe<ros_test::person>("chatter_person",10,doPerson);


        ros::spin();

        return 0;

    }