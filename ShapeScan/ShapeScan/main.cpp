//
//  canny.cpp
//  IMPLecture1
//
//  Created by Nielab Schahrochie on 17.04.15.
//  Copyright (c) 2015 haw. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include <iostream>


using namespace cv;

Mat src_gray;
Mat dst, detected_edges;

//
// globale Variablen
//

int edgeThresh = 1;

//Schwellenwert
int lowThreshold = 150;

//Verhaeltnis 3:1
int ratio = 3;

//Kern=3 fuer Sobel
int kernel_size = 3;

//Ergebnis
const char* ergebnis = "Canny";

//
// CannyThreshold
//

static void CannyThreshold(){
	// Sobel mit Kern 3
	blur(src_gray, detected_edges, Size(3, 3));

	// Canny detector
	Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);

	// schwarzes Bild
	dst = Scalar::all(0);

	//Kanten in schwarzes Bild kopieren
	src_gray.copyTo(dst, detected_edges);
	imshow(ergebnis, dst);
}

int main(){
	/// Load an image
	src_gray = imread("fanta.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	// Matrix mit selben Maﬂen wie src_gray
	dst.create(src_gray.size(), src_gray.type());

	// Anzeigefenster
	namedWindow(ergebnis, WINDOW_AUTOSIZE);

	// Anzeigen
	CannyThreshold(/*0, 0*/);


	waitKey(0);
	return 0;
}