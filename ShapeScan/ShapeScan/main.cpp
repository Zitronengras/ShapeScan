/***
* Created by Carolin Stellmacher on 23.06.15.
*/
#include <opencv2\opencv.hpp>
#include <iostream>
#include <vector>
#include <stdio.h>
#include "Camera.h"


using namespace cv;
using namespace std;

int main(){

	Camera ca;

	VideoCapture cap(0);		// open the default camera
	if (!cap.isOpened()){		// check if we succeded
		cout << "Can't open camera of video file\n" << endl;
		return -1;
	}

	cout << "Press d after you take the two pictures" << endl;
	cout << "Press b to save a background picture" << endl;
	cout << "Press o to save a object picture" << endl;

	return ca.process(cap);
	waitKey(0);
}
