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

Mat frame;

int process(VideoCapture& cap){
	int n = 0;
	char filename[100];
	string windowName = "Video | esc to quit";
	cout << "Press space to save a picture" << endl;

	namedWindow(windowName, CV_WINDOW_KEEPRATIO);

	for (;;){
		cap >> frame;			// get a new Frame from Camera
		if (frame.empty())
			break;

		imshow(windowName, frame);

		char key = (char)waitKey(5);
		switch (key){
		case 27:		// esc -> Quit
			return 0;
		case ' ':		// space -> Save Image 
			sprintf(filename, "Picture%.3d.jpg", n++);		//Name: Picture00n.jpg
			imwrite(filename, frame);
			cout << "Saved" << filename << endl;
			break;
		default:
			break;
		}
	}
	return 0;

}


int main(){

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
	
	return process(cap);
	waitKey(0);

}