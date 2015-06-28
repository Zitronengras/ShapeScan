#ifndef HOUGHLINE_H
#define HOUGHLINE_H

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

class HoughLine{

public:
	HoughLine();
	~HoughLine();

	//Mat greyImage;


	void detectLines();


private:

};

#endif // HOUGHLINE_H


