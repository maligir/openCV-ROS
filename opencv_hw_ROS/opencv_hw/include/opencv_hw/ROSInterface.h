#ifndef ROS_INTERFACE_H
#define ROS_INTERFACE_H

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "ColorFilter.h"

class ROSInterface{

    protected:
    
    ros::NodeHandle _nh;
    image_transport::ImageTransport _it;
    image_transport::Subscriber _sub;
    image_transport::Publisher _blue_pub;
    image_transport::Publisher _green_pub;
    image_transport::Publisher _red_pub;
    image_transport::Publisher _bgr_pub;
    ColorFilter _cf;

    public:

    ROSInterface(ColorFilter& cf);

    ~ROSInterface();

    void imageCB(const sensor_msgs::ImageConstPtr& msg);


};

#endif