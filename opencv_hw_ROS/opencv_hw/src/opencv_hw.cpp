#include "ROSInterface.h"


int main(int argc, char **argv) {
    ros::init(argc, argv, "image_out");
    ColorFilter cf;
    ROSInterface rf(cf);
    ros::spin();
}