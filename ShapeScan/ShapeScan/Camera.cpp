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
