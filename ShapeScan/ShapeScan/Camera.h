#pragma once
#include <opencv2\opencv.hpp>
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace cv;
using namespace std;

class Camera
{
public:
	Camera();
	~Camera();
	Mat frame;
	int process(VideoCapture& cap);
private:
};