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


// CannyThreshold
void CannyEdgeDet::cannyThreshold(){
	edgeThresh = 1;
	lowThreshold = 150;
	ratio = 3:
	kernel_size = 3;
	result = "Canny";

	// Sobel mit Kern 3
	blur(src_gray, detected_edges, Size(3, 3));
	
	// Canny detector
	Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel:size);

	// schwarzes Bild
	dst = Scalar__all(0);

	//Kanten in schwarzes Bild kopieren
	src_gray.copyTo(dst, detected_edges);
	imshow(result, dst);
}

int CannyEdgeDet::runCanny(Mat src_gray){
	/// Load an image
	//src_gray = imread("card.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	// Matrix mit selben Maﬂen wie src_gray
	dst.create(src_gray.size(), src_gray.type());

	// Anzeigefenster
	namedWindow(ergebnis, WINDOW_AUTOSIZE);

	// Anzeigen
	cannyThreshold(/*0, 0*/);
	
}