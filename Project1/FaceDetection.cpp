#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	VideoCapture cap(0);
	Mat img;

	while (true) {
		//string path = "Resources/01.jpeg";
		cap.read(img);

		CascadeClassifier faceCascade;
		faceCascade.load("Resources/haarcascade_frontalface_default.xml");

		if (faceCascade.empty()) cout << "XML file not found/loaded" << endl;

		vector<Rect> faces;
		faceCascade.detectMultiScale(img, faces, 1.1, 7);

		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 255, 0), 2);
		}

		imshow("Image", img);
		waitKey(1);
	}
	return 0;
}