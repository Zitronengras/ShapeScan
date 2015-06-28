/***
* Created by Carolin Stellmacher on 28.06.15.
*/

#include "houghLine.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


HoughLine::HoughLine()
{
}

HoughLine::~HoughLine()
{
}

Mat HoughLine::detectLines(Mat img){

	//stores lines in vector
	vector<Vec2f> lines;

	HoughLines(img, lines, 1, CV_PI / 180, 175);

	Mat imgLines;
	cvtColor(img, imgLines, CV_GRAY2BGR);

	for (int i = 0; i < lines.size(); i++){
		float rho = lines[i][0];
		float theta = lines[i][1];

		double a = cos(theta);
		double b = sin(theta);

		double x0 = a*rho;
		double y0 = b*rho;

		Point pt1(cvRound(x0 + 1000 * (-b)),
			cvRound(y0 + 1000 * (a)));
		Point pt2(cvRound(x0 - 1000 * (-b)),
			cvRound(y0 - 1000 * (a)));

		line(imgLines, pt1, pt2, Scalar(70, 0, 5), 1, 8);
	}

	return imgLines;
}