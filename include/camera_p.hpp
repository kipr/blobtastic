#ifndef _BLOBTASTIC_P_HPP_
#define _BLOBTASTIC_P_HPP_

#include <opencv2/opencv.hpp>

struct CameraPrivate
{
	cv::Mat raw;
	
	cv::Mat rgb;
	bool rgbValid;
	
	cv::Mat resizedRgb;
	bool resizedRgbValid;	
	
	cv::Mat hsv;
	bool hsvValid;
	
	cv::VideoCapture capture;
};

#endif
