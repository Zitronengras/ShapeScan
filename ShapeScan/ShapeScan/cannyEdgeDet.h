#ifndef CANNYEDGEDET_H
#define CANNYEDGEDET_H

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

class CannyEdgeDet{

public:
	CannyEdgeDet();
	~CannyEdgeDet();

	Mat src_gray;
	Mat dst, detected_edges;

	int edgeThresh;

	//Schwellenwert
	int lowThreshold;

	//Verhaeltnis 3:1
	int ratio;

	//Kern=3 fuer Sobel
	int kernel_size;

	//Ergebnis
	const char* result;

	void cannyThreshold();
	int runCanny(Mat image);

private:

};

#endif // CANNYEDGEDET_H


