/***
* Created by Carolin Stellmacher on 23.06.15.
*/

#include <opencv2\opencv.hpp>
#include <iostream>
#include "Camera.h"


using namespace cv;
using namespace std;


int main(){

	Camera ca;

	VideoCapture cap(0);		// open the default camera
	if (!cap.isOpened())		// check if we succeded
		return -1;


	Mat backImg = imread("backgroundImage.jpg");

	// imdecode
	vector<uchar> buff; {
		Mat im = Mat::zeros(1000, 1000, CV_8U);
		vector<int> param = vector<int>(2);
		param[0] = CV_IMWRITE_PNG_COMPRESSION;
		param[1] = 3;
		imencode("backgroundImage.jpg", im, buff, param);
	}

	//Mat backImg = imread("backgroundImage.jpg");
	// BackgroundImage ausgeben
	const char* background = ("BackgroundImage");
	namedWindow(background, WINDOW_AUTOSIZE);
	imshow(background, backImg);

	Mat objImg = imread("objectImage.jpg");
	// ObjectImage ausgeben
	const char* object = ("ObjectImage");
	namedWindow(object, WINDOW_AUTOSIZE);
	imshow(object, objImg);

	return ca.process(cap);


	waitKey(0);

}