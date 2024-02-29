#include<opencv2/opencv.hpp>
#include<math.h>
#include<iostream>
#include<string>
#include<cstdio>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/core/core.hpp>
#include<opencv2/\imgproc/\types_c.h>
#include <opencv2/imgproc/imgproc_c.h>
using namespace std;
using namespace cv;
Mat img, img2, dst, dst2;
string p, path, filename;
#define WINDOW_NAME "Original"
#define WINDOW_NAME1 "Erosion and Dilation"
#define WINDOW_NAME2 "Result"
int chessmen1(void) {
	int n1 = 0;
	dst = Mat::zeros(img2.size(), img2.type());
	dst2 = Mat::zeros(img2.size(), img2.type());
	
	Mat erosion1 = getStructuringElement(MORPH_RECT, Size(3, 3));
	erode(img2, dst, erosion1);	//erosion 侵蝕
	Mat dilate1 = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(dst, dst2, dilate1);	//dilate 膨脹 

	vector<Vec3f> circles;
	HoughCircles(dst2, circles, HOUGH_GRADIENT, 1, 200, 100, 30, 100, 500);
	for (int i = 0;i < circles.size();i++) {
		Point c(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int r = cvRound(cvRound(circles[i][2]));
		if ((r > 151) && (r < 280)) {
			circle(img, c, r, Scalar(0, 100, 255), 15, 8, 0);
			n1++;
		}
	}

	namedWindow(WINDOW_NAME1, WINDOW_NORMAL);
	imshow(WINDOW_NAME1, dst2);
	namedWindow(WINDOW_NAME2, WINDOW_NORMAL);
	imshow(WINDOW_NAME2, img);
	return n1;
}
int main()
{
	int ans = -1;
	path = "C:\\Users\\user\\Desktop\\image processing\\hw\\Assignment7\\";
	cout << "Please enter a file name.(file type):"; //IMG_5702.JPG
	getline(cin, filename);
	p = path + filename;
	img = imread(p);
	if (img.empty())
	{
		cout << "Could not find this file." << endl;
		system("pause");
		return -1;
	}
	namedWindow(WINDOW_NAME, WINDOW_NORMAL); //output original
	imshow(WINDOW_NAME, img);
	img2 = imread(p, IMREAD_GRAYSCALE);//灰階形式讀取圖片
	medianBlur(img2, img2, 5);;
	ans = chessmen1();
	cout << "number of chessmen: " << ans << endl;
	waitKey(0);
	destroyWindow(WINDOW_NAME);
	destroyWindow(WINDOW_NAME1);
	destroyWindow(WINDOW_NAME2);
	return 0; 
}