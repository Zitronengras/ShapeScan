/***
* Created by Carolin Stellmacher on 23.06.15.
*/

#include <opencv2\opencv.hpp>
#include <iostream>
#include "cannyEdgeDet.h"
#include "houghLine.h"
#include "houghCircle.h"

#include <opencv2/highgui/highgui.hpp>		// für SVM
#include <opencv2/ml/ml.hpp>		

using namespace cv;
using namespace std;


void main(){

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

	//SVM Test
	// Data for visual representation
	int width = 512, height = 512;
	Mat imageSVM = Mat::zeros(height, width, CV_8UC3);
	
	 // Set up training data
	float labels[4] = { 1.0, -1.0, -1.0, -1.0 };
	Mat labelsMat(4, 1, CV_32FC1, labels);
	
	float trainingData[4][2] = { { 501, 10 }, { 255, 10 }, { 501, 255 }, { 10, 501 } };
	Mat trainingDataMat(4, 2, CV_32FC1, trainingData);
	
	// Set up SVM’s parameters
	CvSVMParams params;
	params.svm_type = CvSVM:: C_SVC;
	params.kernel_type = CvSVM:: LINEAR;
	params.term_crit = cvTermCriteria(CV_TERMCRIT_ITER, 100, 1e-6);
	
	// Train the SVM
	CvSVM SVM;
	SVM.train(trainingDataMat, labelsMat, Mat(), Mat(), params);
	
	Vec3b green(0, 255, 0), blue(255, 0, 0);
	// Show the decision regions given by the SVM
	for (int i = 0; i < imageSVM.rows; ++i)
	for (int j = 0; j < imageSVM.cols; ++j)
	 {
		Mat sampleMat = (Mat_<float>(1, 2) << j, i);
		float response = SVM.predict(sampleMat);
		
		if (response == 1)
			imageSVM.at<Vec3b>(i, j) = green;
		else if (response == -1)
			imageSVM.at<Vec3b>(i, j) = blue;
		}
	
	// Show the training data
	int thickness = -1;
	int lineType = 8;
	circle(imageSVM, Point(501, 10), 5, Scalar(0, 0, 0), thickness, lineType);
	circle(imageSVM, Point(255, 10), 5, Scalar(255, 255, 255), thickness, lineType);
	circle(imageSVM, Point(501, 255), 5, Scalar(255, 255, 255), thickness, lineType);
	circle(imageSVM, Point(10, 501), 5, Scalar(255, 255, 255), thickness, lineType);
	
	// Show support vectors
	thickness = 2;
	lineType = 8;
	int c = SVM.get_support_vector_count();
	
	for (int i = 0; i < c; ++i)
		{const float* v = SVM.get_support_vector(i);
		circle(imageSVM, Point((int)v[0], (int)v[1]), 6, Scalar(128, 128, 128), thickness, lineType);
	}
	
	imwrite(" result.png", imageSVM); // save the image
	
	imshow(" SVM Simple Example", image); // show it to the user
	
	waitKey(0);
}