#include "houghCircle.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

HoughCircle::HoughCircle()
{
}


HoughCircle::~HoughCircle()
{
}

Mat HoughCircle::detectCircle(Mat sourceGray){
	// 3 floats f�r die Parameter xc, yc und r
	vector<Vec3f> circles;

	// 4.Schritt anwenden der Hough Transformtion f�r Kreise
	HoughCircles(sourceGray,				// Mat-Objekt mit Originalbild in Graustufen
		circles,					// Vektor speichert gefundene Kreise
		CV_HOUGH_GRADIENT,			// Anwendung der Methode ("CV_HOUGH_GRADIENT") Canny-Kantendetektor
		1,							// Inverses Verh�ltnis zwischen der Aufl�sung des Akkumulators und der Bildaufl�sung, 1 -> Aufl�sung Akkumulator = Aufl�sung Originalbild
		sourceGray.rows / 8,			// minimale Distanz zwischen den Kreismittelpunkten der gefundenen Kreise
		150,						// oberer Schwellwert Canny-Kantendetekors
		50,						// Akkumulator-Schwellwert f�r Kreismittelpunkte
		0,							// Minimaler Kreisradius, 0 = keine Einschr�nkung
		0);							// maximaler kreisradius, 0 = keine Einschr�nkung

	// Einzeichnen der gefundenen Kreise
	for (size_t i = 0; i < circles.size(); i++){

		// Kreismittelpunkt bestimmen
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));

		// Kreisradius bestimmen
		int radius = cvRound(circles[i][2]);

		// Mittelpunkt in blau einzeichnen
		circle(sourceGray, center, 4, Scalar(255, 0, 0), -1, 8, 0);

		// Kreiskontur in rot einzeichnen
		circle(sourceGray, center, radius, Scalar(0, 0, 255), 3, 8, 0);
	}
	return sourceGray;

}