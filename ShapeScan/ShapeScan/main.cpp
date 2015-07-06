/***
* Created by Carolin Stellmacher on 23.06.15.
*/

#include <opencv2\opencv.hpp>
#include <iostream>
#include "cannyEdgeDet.h"
#include "houghLine.h"
#include "houghCircle.h"
#include "Camera.h"



#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"


using namespace cv;
using namespace std;

void readme();

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


int main(int argc, char** argv){

	/*if (argc != 3)
	{
		readme(); return -1;
	}*/

	Mat img_1 = imread("card.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat img_2 = imread("card.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	if (!img_1.data || !img_2.data)
	{
		std::cout << " --(!) Error reading images " << std::endl; return -1;
	}

	//-- Step 1: Detect the keypoints using SURF Detector
	int minHessian = 400;

	SurfFeatureDetector detector(minHessian);

	std::vector<KeyPoint> keypoints_1, keypoints_2;

	detector.detect(img_1, keypoints_1);
	detector.detect(img_2, keypoints_2);

	//-- Step 2: Calculate descriptors (feature vectors)
	SurfDescriptorExtractor extractor;

	Mat descriptors_1, descriptors_2;

	extractor.compute(img_1, keypoints_1, descriptors_1);
	extractor.compute(img_2, keypoints_2, descriptors_2);

	//-- Step 3: Matching descriptor vectors using FLANN matcher
	FlannBasedMatcher matcher;
	std::vector< DMatch > matches;
	matcher.match(descriptors_1, descriptors_2, matches);

	double max_dist = 0; double min_dist = 100;

	//-- Quick calculation of max and min distances between keypoints
	for (int i = 0; i < descriptors_1.rows; i++)
	{
		double dist = matches[i].distance;
		if (dist < min_dist) min_dist = dist;
		if (dist > max_dist) max_dist = dist;
	}

	printf("-- Max dist : %f \n", max_dist);
	printf("-- Min dist : %f \n", min_dist);

	//-- Draw only "good" matches (i.e. whose distance is less than 2*min_dist,
	//-- or a small arbitary value ( 0.02 ) in the event that min_dist is very
	//-- small)
	//-- PS.- radiusMatch can also be used here.
	std::vector< DMatch > good_matches;

	for (int i = 0; i < descriptors_1.rows; i++)
	{
		if (matches[i].distance <= max(2 * min_dist, 0.02))
		{
			good_matches.push_back(matches[i]);
		}
	}

	//-- Draw only "good" matches
	Mat img_matches;
	drawMatches(img_1, keypoints_1, img_2, keypoints_2,
		good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
		vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

	//-- Show detected matches
	imshow("Good Matches", img_matches);

	for (int i = 0; i < (int)good_matches.size(); i++)
	{
		printf("-- Good Match [%d] Keypoint 1: %d  -- Keypoint 2: %d  \n", i, good_matches[i].queryIdx, good_matches[i].trainIdx);
	}

	waitKey(0);

	return 0;

	/*VideoCapture cap(0);		// open the default camera
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
	waitKey(0);*/

}

/**
* @function readme
*/
void readme()
{
	std::cout << " Usage: ./SURF_FlannMatcher <img1> <img2>" << std::endl;
}