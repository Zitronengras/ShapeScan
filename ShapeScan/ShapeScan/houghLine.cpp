/***
* Created by Carolin Stellmacher on 28.06.15.
*/

#include "houghLine.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

HoughLine::HoughLine()
{
}

HoughLine::~HoughLine()
{
}

void HoughLine::detectLines(){
	greyImage = imread("card.jpg", CV_LOAD_IMAGE_GRAYSCALE);
}