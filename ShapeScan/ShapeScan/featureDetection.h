#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class featureDetection
{
public:
	featureDetection();
	~featureDetection();

	Mat detect(Mat img);
};

