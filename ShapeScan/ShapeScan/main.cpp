#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void firstTask() {
	Mat logoImg = imread("logo.png");

	for (int x = 0; x < logoImg.rows; x++) {
		for (int y = 0; y < logoImg.cols; y++) {
			//Vec3b intensity = image.at<Vec3b>(y, x);
			if (logoImg.at<Vec3b>(x, y) == Vec3b(0, 0, 0)) {
				logoImg.at<Vec3b>(x, y) = Vec3b(0, 0, 255);
			}
		}
	}

	namedWindow("Window");
	imshow("Window", logoImg);

	waitKey(0);
}

void secondTask() {
	Mat lenaImg = imread("lena.jpg");

	namedWindow("LenaWindow");
	imshow("LenaWindow", lenaImg);

	waitKey(0);
}

void main()
{
	//firstTask();
	secondTask();



}