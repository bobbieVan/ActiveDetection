// FaceLivingDetector.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>

#include "FaceLivingDetector.h"

using namespace std;
using namespace cv;

int main()
{
	const string model_path = "..\\models\\shape_predictor_68_face_landmarks.dat";
	FaceLivingDetector::init(model_path);

	bool begin = true;
	VideoCapture cp(0);
	Mat frame;
	stringstream ss;
	while (true) {
		cp >> frame;
		if (frame.empty()) continue;
		int ret = FaceLivingDetector::execute(frame, FaceLivingDetector::Action::blink, 10000, begin);
		begin = false;
		cout << ret << endl;
		imshow("frame", frame);
		waitKey(10);
	}

    return 0;
}

