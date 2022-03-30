#ifndef COLOR_FILTER_H
#define COLOR_FILTER_H

#include <opencv2/opencv.hpp>

#include <string>
#include <vector>

class ColorFilter {
protected:
    cv::Mat _frame;
    std::vector<cv::Mat> _chans;

    //blue
    cv::Mat _sub_blue;
    cv::Mat _thresh_blue;
    cv::Mat _mask_blue;
    cv::Mat _img_blue;

    //green
    cv::Mat _sub_green;
    cv::Mat _thresh_green;
    cv::Mat _mask_green;
    cv::Mat _img_green;

    //red
    cv::Mat _sub_red;
    cv::Mat _thresh_red;
    cv::Mat _mask_red;
    cv::Mat _img_red;

    //all three
    cv::Mat _img;


public:
    void processImage(cv::Mat img);

    void split();

    void findBlue();
    void findGreen();
    void findRed();
    void findBGR();

    void showResult();

};

#endif
