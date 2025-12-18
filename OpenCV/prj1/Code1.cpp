#include "opencv2/opencv.hpp"
#include <iostream>

void show1() {

cv::Mat image1 = cv::imread("lenna.png");
cv::Mat image2 = cv::imread("dog.jpg");
cv::Mat image3;

image3 = image1.clone();
// for 문으로 복사하는 루틴

if(image1.empty() or image2.empty() or image3.empty()) {
	std::cerr << "Could not open or find the images!" << std::endl;
	return ;
}	

std::cout << "레나는 몇 차원? : " << image1.dims << std::endl;
std::cout << "열(Column) ? : " << image1.cols << std::endl;
std::cout << "행(Row) ? : " << image1.rows << std::endl;

std::cout << "강아지는 몇 차원? : " << image2.dims << std::endl;
std::cout << "열(Column) ? : " << image2.cols << std::endl;
std::cout << "행(Row) ? : " << image2.rows << std::endl;

cv::namedWindow("Image1");
cv::imshow("Image1", image1);
cv::namedWindow("Image2");
cv::imshow("Image2", image2);
cv::namedWindow("Image3");
cv::imshow("Image3", image3);
cv::waitKey(0);
cv::destroyAllWindows();

}

void show2() {

	cv::namedWindow("Color");
	for (int i = 0; i < 256; ++i) {
		cv::Mat image(512, 512, CV_8UC3, cv::Scalar(0, 0, i)); //Red
		cv::imshow("Color", image);		
		cv::waitKey(10);
	}
	for (int i = 0; i < 256; ++i) {
		cv::Mat image(512, 512, CV_8UC3, cv::Scalar(0, i, 0)); //Green
		cv::imshow("Color", image);		
		cv::waitKey(10);
	}
	for (int i = 0; i < 256; ++i) {
		cv::Mat image(512, 512, CV_8UC3, cv::Scalar(i, 0, 0)); //Blue
		cv::imshow("Color", image);
		cv::waitKey(10);
	}
	for (int i = 255; i >= 0; --i) {
		cv::Mat image(512, 512, CV_8UC3, cv::Scalar(i, i, i)); //Red
		cv::imshow("Color", image);
		
		cv::waitKey(10);


	}

	cv::waitKey(0);	
	cv::destroyAllWindows();

}