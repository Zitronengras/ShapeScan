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

	return ca.process(cap);
	waitKey(0);

}