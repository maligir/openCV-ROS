#include "ColorFilter.h"

using namespace std;
using namespace cv;

void ColorFilter::processImage(cv::Mat img) {
    _frame = img;
    split();
    findBlue();
    findGreen();
    findRed();
   findBGR();
    showResult();
}

void ColorFilter::split() {
    cv::split(_frame, _chans);
}

void ColorFilter::showResult() {
    cv::waitKey(200);
    //PROBLEM 1
    //cv::imshow("color", _frame);
    //PROBLEM 2: B
    //cv::imshow("blue", _chans[0]);
    //PROBLEM 2: G
    //cv::imshow("green", _chans[1]);
    //PROBLEM 2: R
    //cv::imshow("red", _chans[2]);
    //subtracts all red from the blue 
    // PROBLEM 3: Blue Subtraction
    // cv::imshow("blue_subtraction", _sub_blue);
    // PROBLEM 3: Blue Threshold
    // cv::imshow("blue_threshold", _thresh_blue);
    // PROBLEM 3: Blue Contour Mask
    // cv::imshow("blue_contour_mask", _mask_blue);
    // PROBLEM 3: Blue Image
    // cv::imshow("blue_image", _img_blue);
    //PROBLEM 4: Green Subtraction
    // cv::imshow("green_subtraction", _sub_green);
    //PROBLEM 4: Green Threshold
    // cv::imshow("green_threshold", _thresh_green);
    // PROBLEM 4: Green Contour Mask
    // cv::imshow("green_contour_mask", _mask_green);
    //PROBLEM 4: Green Image
    // cv::imshow("green_image", _img_green);
    //PROBLEM 5: Red Subtraction
    // cv::imshow("red_subtraction", _sub_red);
    //PROBLEM 5: Red Threshold
    // cv::imshow("red_threshold", _thresh_red);
    // PROBLEM 5: Red Contour Mask
    // cv::imshow("red_contour_mask", _mask_red);
    //PROBLEM 5: Red Image
    // cv::imshow("red_image", _img_red);
    //PROBLEM 6: ALL THREE
    cv::imshow("all_three", _img);
}

void ColorFilter::findBlue() {
        Mat sub;
        subtract(_chans[0], _chans[2], sub);

        //creates a minimum threshold for showing all of this color
        Mat thresh;
        threshold(sub, thresh, 50, 255, cv::THRESH_BINARY);
        
        std::vector<cv::Mat> contours;
        std::vector<cv::Vec4i> hierarchy;
        //finds the contours of the shapes
        findContours(thresh, contours, hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);

        int maxSizeContour = 0;
        int maxContourSize = 0;
        for(int i = 0; i < contours.size(); i++) {
            int contourSize = cv::contourArea(contours[i]);
            //finds the max area of a certain contour
            if(contourSize > maxContourSize) {
                maxSizeContour = i;
                maxContourSize = contourSize;
            }
        }
        
        cv::Mat contourimage = cv::Mat::zeros(_frame.rows, _frame.cols, CV_8UC3);
        //draws the contours on contourimage
        drawContours(   contourimage, contours, maxSizeContour, cv::Scalar(255,255,255),
                        cv::LineTypes::FILLED, 8, hierarchy );

        cv::Mat contourmask = cv::Mat::zeros(_frame.rows, _frame.cols, CV_8UC1);
        //creates the mask and draws contours on mask
        drawContours( contourmask, contours, maxSizeContour, cv::Scalar(255), cv::LineTypes::FILLED, 8, hierarchy );

        cv::Mat img;
        //draws the imag with contourmask
        _frame.copyTo(img, contourmask);

        //populates the class variables
        _img_blue = img;
        _mask_blue = contourmask;
        _thresh_blue = thresh;
        _sub_blue = sub;
}

void ColorFilter::findGreen() {
        Mat sub;
        subtract(_chans[1], _chans[0], sub);

        //creates a minimum threshold for showing all of this color
        Mat thresh;
        threshold(sub, thresh, 50, 255, cv::THRESH_BINARY);
        
        std::vector<cv::Mat> contours;
        std::vector<cv::Vec4i> hierarchy;
        //finds the contours of the shapes
        findContours(thresh, contours, hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);

        int maxSizeContour = 0;
        int maxContourSize = 0;
        for(int i = 0; i < contours.size(); i++) {
            int contourSize = cv::contourArea(contours[i]);
            //finds the max area of a certain contour
            if(contourSize > maxContourSize) {
                maxSizeContour = i;
                maxContourSize = contourSize;
            }
        }
        
        cv::Mat contourimage = cv::Mat::zeros(_frame.rows, _frame.cols, CV_8UC3);
        //draws the contours on contourimage
        drawContours(   contourimage, contours, maxSizeContour, cv::Scalar(255,255,255),
                        cv::LineTypes::FILLED, 8, hierarchy );

        cv::Mat contourmask = cv::Mat::zeros(_frame.rows, _frame.cols, CV_8UC1);
        //creates the mask and draws contours on mask
        drawContours( contourmask, contours, maxSizeContour, cv::Scalar(255), cv::LineTypes::FILLED, 8, hierarchy );

        cv::Mat img;
        //draws the imag with contourmask
        _frame.copyTo(img, contourmask);

        //populates the class variables
        _img_green = img;
        _mask_green = contourmask;
        _thresh_green = thresh;
        _sub_green = sub;
}

void ColorFilter::findRed() {
        Mat sub;
        subtract(_chans[2], _chans[1], sub);

        //creates a minimum threshold for showing all of this color
        Mat thresh;
        threshold(sub, thresh, 50, 255, cv::THRESH_BINARY);
        
        std::vector<cv::Mat> contours;
        std::vector<cv::Vec4i> hierarchy;
        //finds the contours of the shapes
        findContours(thresh, contours, hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);

        int maxSizeContour = 0;
        int maxContourSize = 0;
        for(int i = 0; i < contours.size(); i++) {
            int contourSize = cv::contourArea(contours[i]);
            //finds the max area of a certain contour
            if(contourSize > maxContourSize) {
                maxSizeContour = i;
                maxContourSize = contourSize;
            }
        }
        
        cv::Mat contourimage = cv::Mat::zeros(_frame.rows, _frame.cols, CV_8UC3);
        //draws the contours on contourimage
        drawContours(   contourimage, contours, maxSizeContour, cv::Scalar(255,255,255),
                        cv::LineTypes::FILLED, 8, hierarchy );

        cv::Mat contourmask = cv::Mat::zeros(_frame.rows, _frame.cols, CV_8UC1);
        //creates the mask and draws contours on mask
        drawContours( contourmask, contours, maxSizeContour, cv::Scalar(255), cv::LineTypes::FILLED, 8, hierarchy );

        cv::Mat img;
        //draws the imag with contourmask
        _frame.copyTo(img, contourmask);

        //populates the class variables
        _img_red = img;
        _mask_red = contourmask;
        _thresh_red = thresh;
        _sub_red = sub;
}

void ColorFilter::findBGR() {

    //empty masks
    cv::Mat red_blue_mask = cv::Mat::zeros(_frame.rows, _frame.cols, CV_8UC1);
    cv::Mat green_blue_mask = cv::Mat::zeros(_frame.rows, _frame.cols, CV_8UC1);
    cv::Mat mask = cv::Mat::zeros(_frame.rows, _frame.cols, CV_8UC1);

    //empty images
    cv::Mat red_blue_img = cv::Mat::zeros(_frame.rows, _frame.cols, CV_8UC1);
    cv::Mat green_blue_img = cv::Mat::zeros(_frame.rows, _frame.cols, CV_8UC1);
    _img = cv::Mat::zeros(_frame.rows, _frame.cols, CV_8UC1);

    //combine masks
    cv::bitwise_or(_mask_red, _mask_blue, red_blue_mask);
    cv::bitwise_or(_mask_blue, _mask_green, green_blue_mask);
    cv::bitwise_or(red_blue_mask, green_blue_mask, mask);

    //combine images
    cv::bitwise_or(_img_blue, _img_red, red_blue_img);
    cv::bitwise_or(_img_green, _img_blue, green_blue_img);
    cv::bitwise_or(red_blue_img, green_blue_img, _img);

    _frame.copyTo(_img, mask);
}