#include "ros/ros.h"
#include "/home/liuyihan/catkin_ws/devel/include/ros_test/person.h"
#include "std_msgs/Header.h"
#include<sstream>

int main(int argc, char *argv[])
    {
        //设置编码
        setlocale(LC_ALL,"");

        ros::init(argc , argv, "publish_person");

        ros::NodeHandle nh;

        ros::Publisher pub = nh.advertise<ros_test::person>("chatter_person",1000);

        ros_test::person p;



        int count = 0;

        ros::Time time_now(ros::Time::now());
        ros::Rate r(1);
        while(ros::ok())
        {

            p.age = 22;
            p.height = 65.0;
            p.name = "liuyihan";
            p.stamp = ros::Time::now();
            pub.publish(p);

            ROS_INFO("my name is %s  my age is %d  my height is %f  time is %f"
                    ,p.name.c_str(), p.age, p.height,p.stamp.toSec() - time_now.toSec());

            r.sleep();

            count++;

            ros::spinOnce();

        }

        return 0;

    }