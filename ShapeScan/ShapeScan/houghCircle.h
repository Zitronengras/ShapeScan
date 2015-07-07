#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class HoughCircle
{
public:
	HoughCircle();
	~HoughCircle();
	Mat detectCircle(Mat img);
	private:
};

