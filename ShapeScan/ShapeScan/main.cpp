/***
* Created by Carolin Stellmacher on 23.06.15.
*/

#include <opencv2\opencv.hpp>
#include <iostream>
#include "cannyEdgeDet.h"

using namespace std;
using namespace cv;


void main(){

	CannyEdgeDet cannyEdgeDet;
	cannyEdgeDet.runCanny();

	waitKey(0);
}