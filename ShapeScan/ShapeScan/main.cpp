/***
* Created by Carolin Stellmacher on 23.06.15.
*/

#include <opencv2\opencv.hpp>
#include <iostream>
#include "cannyEdgeDet.h"
#include "houghLine.h"


using namespace cv;


void main(){

	CannyEdgeDet cannyEdgeDet;
	HoughLine hougLine;
	//load image
	Mat image = imread("card.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	//store image of canny
	Mat cannyImg = cannyEdgeDet.runCanny(image);

	//store image of houghLine
	Mat houghLineImg = hougLine.detectLines(cannyImg);

	namedWindow("ShapeScan", WINDOW_AUTOSIZE);
	imshow("ShapeScan", houghLineImg);

	waitKey(0);
}