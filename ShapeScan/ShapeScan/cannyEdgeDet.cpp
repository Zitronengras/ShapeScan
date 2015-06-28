/**
 *
 * Created by Nielab Schahrochie on 17.04.15.
 * Copyright (c) 2015 haw. All rights reserved.
 *
 */

#include "cannyEdgeDet.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

CannyEdgeDet::CannyEdgeDet()
{
}

CannyEdgeDet::~CannyEdgeDet()
{
}

const char* result = "Canny";
Mat dst;

// CannyThreshold
void CannyEdgeDet::cannyThreshold(){
	int edgeThresh = 1;
	int lowThreshold = 150;
	int ratio = 3;
	int kernel_size = 3;
	Mat detected_edges;

	// Sobel mit Kern 3
	blur(src_gray, detected_edges, Size(3, 3));
	
	// Canny detector
	Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);

	// schwarzes Bild
	dst = Scalar::all(0);

	//Kanten in schwarzes Bild kopieren
	src_gray.copyTo(dst, detected_edges);
	imshow(result, dst);
}

void CannyEdgeDet::runCanny(Mat src_gray){
	/// Load an image
	src_gray = imread("fanta.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	// Matrix mit selben Maﬂen wie src_gray
	dst.create(src_gray.size(), src_gray.type());

	// Anzeigefenster
	namedWindow(result, WINDOW_AUTOSIZE);

	// Anzeigen
	cannyThreshold(/*0, 0*/);
	
}