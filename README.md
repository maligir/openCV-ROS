# ROS Color Filter

This project contains a ROS package for a color filter node, which processes images to filter and highlight red, green, and blue colors separately. It makes use of the OpenCV library to perform image processing operations. The package also supports processing of AVI video files.

## How It Works

This project utilizes the OpenCV library to filter out and identify the three main colors: Red, Green, and Blue. It uses color subtraction, thresholding, contour finding, and masking techniques to separate each color and highlight it on the processed image. The resultant images are then published using ROS for visualization or further processing.

## Components

1. **ColorFilter:** This class performs the color filtering tasks. It has methods for processing an input image and separate it into its red, green, and blue components.

2. **ROSInterface:** This class provides an interface between the ColorFilter class and the ROS framework. It has an image callback function that receives incoming ROS image messages, passes them to the ColorFilter for processing, and then publishes the processed images as ROS messages.

3. **ReadAVI:** This class enables the processing of AVI video files through the ColorFilter. It reads frames from the video file one by one and passes them to the ColorFilter for processing.

## How to Build and Run the Project

Ensure you have ROS and OpenCV installed in your system before building and running this project.

To build:

```sh
cd catkin_ws/src
git clone <repository>
cd ..
catkin_make
```

To run:

```sh
source devel/setup.bash
roslaunch color_filter color_filter.launch
```

## Subscription and Publication Topics

The node subscribes to:

- `/kinect2/hd/image_color` - Input images for processing

The node publishes to:

- `blue_cup` - Processed images highlighting blue color
- `green_cup` - Processed images highlighting green color
- `red_cup` - Processed images highlighting red color
- `bgr_cup` - Processed images highlighting all three colors

## Limitations and Assumptions

This project is primarily designed to work with the Kinect2 color image topic (`/kinect2/hd/image_color`). The project may require modifications to work with different image sources or different color spaces.

This code has not been tested under various lighting conditions. Changes in ambient light can affect the color detection performance.

## Future Work

This project can be extended to filter out other colors or multiple specific colors. It could be modified to identify and track colored objects or to perform color-based segmentation. Also, it can be extended to support other types of image sources or video formats.

## Contributions

Contributions to this project are welcome! Please fork the repository and open a pull request with your changes.
