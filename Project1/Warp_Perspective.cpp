#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

float warpedImageWidth = 250, warpedImageHeight = 350;
Mat matrix, imgWarp;

int main() {

	string path = "Resources/cards.jpg";
	Mat img = imread(path);
	
	Point2f imgSrc[4] = { {530, 150}, {771, 190}, {405, 395}, {674, 457} };
	Point2f imgDst[4] = { {0.0f, 0.0f}, {warpedImageWidth, 0.0f}, {0.0f, warpedImageHeight}, {warpedImageWidth, warpedImageHeight} };

	matrix = getPerspectiveTransform(imgSrc,imgDst);
	warpPerspective(img, imgWarp, matrix, Point(warpedImageWidth, warpedImageHeight));

	for (int i = 0; i < 4; i++) circle(img, imgSrc[i], 10, Scalar(255, 255, 0), FILLED);

	imshow("ImageView", img);
	imshow("WarpedImage", imgWarp);
	waitKey(0);

	return 0;
}