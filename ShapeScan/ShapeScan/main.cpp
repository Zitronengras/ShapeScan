/***
* Created by Carolin Stellmacher on 23.06.15.
*/

#include <opencv2\opencv.hpp>
#include <iostream>
#include "cannyEdgeDet.h"
#include "houghLine.h"


using namespace std;
using namespace cv;


void main(){

	Mat image = imread("card.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	//CannyEdgeDet cannyEdgeDet;
	//cannyEdgeDet.runCanny();

	HoughLine hougLine;
	namedWindow("HoughLine", WINDOW_AUTOSIZE);
	imshow("HoughLine", hougLine.detectLines(image));
	


	waitKey(0);
}