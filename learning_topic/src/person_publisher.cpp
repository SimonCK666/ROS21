/**
 * 该例程将发布 /person_info 话题，自定义消息类型 learning_topic::Persion
 */

#include <ros/ros.h>
#include "learning_topic/Person.h"

int main(int argc, char **argv)
{
    // ROS 节点初始化
    ros::init(argc, argv, "person_publisher");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个 Publisher，发布名 /person_info 的 topic，消息类型为 learning_topic::Persion, 队列长度 10
    ros::Publisher person_info_pub = n.advertise<learning_topic::Person>("/person_info", 10);

    // 设置循环的频率
    ros::Rate loop_rate(1);

    int count = 0;
    while (ros::ok())
    {
        /* 初始化 learning_topic::Persion 类型的消息 */
        learning_topic::Person person_msg;
        person_msg.name = "Simon";
        person_msg.age = 22;
        person_msg.sex = learning_topic::Person::male;

        // 发布消息
        person_info_pub.publish(person_msg);

        ROS_INFO("Publish Person Info: name: %s,  age: %d,  sex: %d", person_msg.name.c_str(), person_msg.age, person_msg.sex);

        // 按照循环频率延时
        loop_rate.sleep();
    }

    return 0;
    
}
