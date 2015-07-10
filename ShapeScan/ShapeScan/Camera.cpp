#include "Camera.h"
#include <iostream>
#include <opencv2\opencv.hpp>
#include <vector>
#include <stdio.h>

using namespace cv;
using namespace std;

Camera::Camera()
{
}


Camera::~Camera()
{
}

int Camera::process(VideoCapture& cap){
	char filename[20];
	string windowName = "Video | esc to quit | b to save backgroundImage | o to save objectImage";
	cout << "Press b to save a background picture" << endl;
	cout << "Press o to save a object picture" << endl;

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
		case 98:		// b -> Save backgroundImage 
			sprintf(filename, "backgroundImage.jpg");		
			imwrite(filename, frame);
			cout << "Saved " << filename << endl;
			break;
		case 111:		// o -> Save objectImage
			sprintf(filename, "objectImage.jpg");
			imwrite(filename, frame);
			cout << "Saved " << filename << endl;
			break;
		default:
			break;
		}
	}
	return 0;

}