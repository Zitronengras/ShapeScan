#ifndef HOUGHLINE_H
#define HOUGHLINE_H

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class HoughLine{

public:
	HoughLine();
	~HoughLine();

	Mat detectLines(Mat img);

private:

};

#endif // HOUGHLINE_H


