/***
* Created by Carolin Stellmacher on 23.06.15.
*/

#include <opencv2\opencv.hpp>
#include <iostream>
#include "cannyEdgeDet.h"
#include "houghLine.h"
#include "houghCircle.h"

using namespace cv;
using namespace std;


void main(){

	CannyEdgeDet cannyEdgeDet;
	HoughLine hougLine;
	HoughCircle houghCircle;
	//load image
	Mat image = imread("card.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	//store image of canny
	Mat cannyImg = cannyEdgeDet.runCanny(image);

	//store image of houghLine
	Mat houghLineImg = hougLine.detectLines(cannyImg);

	namedWindow("ShapeScanLine", WINDOW_AUTOSIZE);
	imshow("ShapeScanLine", houghLineImg);

	//store image of houghCircle
	Mat houghCircleImg = houghCircle.detectCircle(cannyImg);

	namedWindow("ShapeScanCircle", WINDOW_AUTOSIZE);
	imshow("ShapeScanCircle", houghCircleImg);

	waitKey(0);
}