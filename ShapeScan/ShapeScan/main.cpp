/***
* Created by Carolin Stellmacher on 23.06.15.
*/

#include <opencv2\opencv.hpp>
#include <iostream>
#include "cannyEdgeDet.h"
#include "houghLine.h"
#include "houghCircle.h"
#include "Camera.h"

using namespace cv;
using namespace std;


int main(){

	Camera ca;

	VideoCapture cap(0);		// open the default camera
	if (!cap.isOpened())		// check if we succeded
		return -1;

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
	
	return ca.process(cap);
	waitKey(0);

}