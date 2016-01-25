#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "laser_receiver1/rplidar_result.h"
#include "laser_rev.h"

void SignalinQt::setvalue(float num)
{
     DofRplidar=num;
}

float SignalinQt::getvalue(void)
{
    return DofRplidar;
}

void SignalinQt::SendSignal(void)
{
    emit SendRange();

}
void chatterCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
    //定义消息，这个节点可以publish这个消息
    process_result.min_range=6;
    float range;
	bool data_p_start=false;
	for(int i=0 ; i < msg->ranges.size();i++){
		if(data_p_start==false)
		{
			if(msg->ranges[i]==std::numeric_limits<float>::infinity())
			{
				continue;
			}
			else
			{
				data_p_start=true;
                range=msg->ranges[i];
			}
		}
		else
		{
            if(range>msg->ranges[i])
			{
                range=msg->ranges[i];
			}

		}
	}
    process_result.min_range=range;
    range_min=range;
    aa.SendSignal();
}

void Laser_infomation::run()
{
	//接收以下话题
    ros::NodeHandle n;
    ros::Subscriber sub=n.subscribe("scan",1000,chatterCallback);
    ros::Publisher laser_process_pub=n.advertise<laser_receiver1::rplidar_result>("rplidar_info",1000);
    ros::Rate loop_rate(10);
    while(ros::ok())
    {
        laser_process_pub.publish(process_result);
        ros::spinOnce();
        loop_rate.sleep();
    }
  //  ros::spin();
}
