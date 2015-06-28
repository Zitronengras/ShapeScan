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

	Mat image = imread("fanta.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	CannyEdgeDet cannyEdgeDet;
	HoughLine houghLine;

	cannyEdgeDet.runCanny(image);
	houghLine.detectLines();
	

	waitKey(0);
}