# ! /usr/bin/env python3
# -*- coding: utf-8 -*-
# 该例程将发布 /person_info 话题，自定义消息类型 learning_topic::Persion

import rospy
from learning_topic.msg import Person

def velocity_publisher():
    # ROS 节点初始化
    rospy.init_node("person_publisher", anonymous=True)

    # 创建一个 Publisher，发布名为 /person_info 的 topic，消息类型为 learning_topic::Person，队列长度 10
    person_info_pub = rospy.Publisher('/person_info', Person, queue_size=10)

    # 设置循环频率
    rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        # 初始化 learning_topic::Person 类型的消息
        person_msg = Person()
        person_msg.name = "Simon"
        person_msg.age = 22
        person_msg.sex = Person.male

        # 发布消息
        person_info_pub.publish(person_msg)
        rospy.loginfo("Publish person message [%s, %d, %d]", person_msg.name, person_msg.age, person_msg.sex)

        # 按照循环频率延时
        rate.sleep()

if __name__ == "__main__":
    try:
        velocity_publisher()
    except rospy.ROSInterruptException:
        pass
