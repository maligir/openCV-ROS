#include "ROSInterface.h"

ROSInterface::ROSInterface(ColorFilter& cf) : _it(_nh){
    _cf = cf;
    //create subscriber
    _sub = _it.subscribe("/kinect2/hd/image_color", 1, &ROSInterface::imageCB, this);
    //advertise all the publishers
    _blue_pub = _it.advertise("blue_cup", 1);
    _green_pub = _it.advertise("green_cup", 1);
    _red_pub = _it.advertise("red_cup", 1);
    _bgr_pub = _it.advertise("bgr_cup", 1);
}

ROSInterface::~ROSInterface(){
    //deconstructor empty
}

void ROSInterface::imageCB(const sensor_msgs::ImageConstPtr& msg){
    cv_bridge::CvImagePtr cv_ptr;
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);

    //process image
    _cf.processImage(cv_ptr->image);

    //publish each image
    sensor_msgs::ImagePtr blue_msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", _cf.getBlueImage()).toImageMsg();
    _blue_pub.publish(blue_msg);
    sensor_msgs::ImagePtr green_msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", _cf.getGreenImage()).toImageMsg();
    _green_pub.publish(green_msg);
    sensor_msgs::ImagePtr red_msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", _cf.getRedImage()).toImageMsg();
    _red_pub.publish(red_msg);
    sensor_msgs::ImagePtr bgr_msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", _cf.getBGRImage()).toImageMsg();
    _bgr_pub.publish(bgr_msg);
}