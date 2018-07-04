// IPcamera.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdio.h>
#include "opencv.hpp"

using namespace std;
using namespace cv;

int main() {
	//"rtsp://username:pass@192.168.1.115:554"
	//"http://username:pass@cam_address/axis-cgi/mjpg/video.cgi?resolution=640x480&req_fps=30&.mjpg"
	//const std::string videoStreamAddress = "http://admin:123456@192.168.1.103/axis-cgi/mjpg/video.cgi?resolution=640x480&req_fps=30&.mjpg";
	//const std::string videoStreamAddress = "http://192.168.1.103:80/cgi-bin/CGIStream.cgi?cmd=GetMJStream&usr=admin&pwd=123456";
	//const std::string videoStreamAddress = "http://192.168.1.103:80/videostream.cgi?user=admin&pwd=123456&.mjpg";  //这个可以网页打开
	//const std::string videoStreamAddress = "GET /decoder_control.cgi?command=28&user=admin&pwd=123456\r\nHost:192.168.1.103\r\n\r\n";
	//const std::string videoStreamAddress = "http://192.168.1.103/videostream.cgi?user=admin&pwd=123456&resolution=640x480&req_fps=30&.mjpg";
	VideoCapture camera;
	camera.open("rtsp://EZVIZ C6C:LCUPGV@192.168.1.13:554");

	//const std::string videoStreamAddress = "rtsp://EZVIZ C6C:LCUPGV@192.168.1.13:554";
	//CvCapture *camera = cvCaptureFromFile(videoStreamAddress.c_str());
	//if (camera == NULL)
	//	printf("camera is null\n");
	//else
	//	printf("camera is not null");
	if (camera.isOpened())
		printf("yes");

	cvNamedWindow("img");
	while (cvWaitKey(10) != atoi("q")) {
		double t1 = (double)cvGetTickCount();
		IplImage *img = cvQueryFrame(camera);
		double t2 = (double)cvGetTickCount();
		printf("time: %gms  fps: %.2g\n", (t2 - t1) / (cvGetTickFrequency()*1000.), 1000. / ((t2 - t1) / (cvGetTickFrequency()*1000.)));
		cvShowImage("CvCapture", img);
	}
	cvReleaseCapture(&camera);

	//cv::VideoCapture vcap;
	//cv::Mat img1;
	//if(!vcap.open(videoStreamAddress)){
	//	std::cout << "Error opening video stream or file" << std::endl;
	//}
	//cvNamedWindow("VideoCapture");
	//while (cvWaitKey(10)!=atoi("q")){
	//	if(!vcap.read(img1)) {
	//		std::cout << "No frame" << std::endl;
	//		cv::waitKey();
	//	}
	//	cv::imshow("VideoCapture", img1);
	//}
}
