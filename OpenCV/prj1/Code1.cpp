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
}

void show3() {
	cv::Mat img1 = cv::Mat::zeros(512,512,CV_8UC1);
	cv::Mat img2 = cv::Mat::ones(512,512,CV_8UC1);
	cv::Mat img3 = cv::Mat::eye(512,512,CV_8UC1)*255;

	cv::namedWindow("Image1");
	cv::imshow("Image1", img1);	

	cv::namedWindow("Image2");
	cv::imshow("Image2", img2);	

	cv::namedWindow("Image3");
	cv::imshow("Image3", img3);	

	cv::waitKey(0);	
	cv::destroyAllWindows();

}

void show4() {
	
	cv::Mat imgDog= cv::imread("dog.bmp");

	if(imgDog.empty()) {
		std::cerr << "파일이 없습니다." << std::endl;
		return;
	}

	cv::namedWindow("Dog");
	cv::imshow("Dog", imgDog);

	cv::Mat imgClonDog = imgDog.clone();

	cv::Mat img3;	
	imgDog.copyTo(img3); // copied dog

	cv::Mat img4 = imgDog; //shallow copy
	imgDog.setTo(cv::Scalar(0, 255, 255)); // yellow color	
	
	cv::namedWindow("ClonDog");
	cv::imshow("ClonDog", imgClonDog);

	cv::namedWindow("Copied Dog");
	cv::imshow("Copied Dog", img3);
	
	cv::namedWindow("Copied Dog2");
	cv::imshow("Copied Dog2", img4);

	cv::waitKey(0);
	cv::destroyAllWindows();
}

void show5() {
	cv::Mat imgCat = cv::imread("cat.bmp");
	cv::Mat notCat = ~imgCat;
	cv::Mat img3 = imgCat(cv::Rect(220, 120, 340, 240)); // 영역을 분할하라는 명령어

	cv::imread("Cat", imgCat);
	cv::namedWindow("Cat");
	cv::imshow("Cat", imgCat);	

	cv::namedWindow("~Cat");
	cv::imshow("~Cat", notCat);	

	cv::namedWindow("Region of Cat");
	cv::imshow("Region of Cat", img3);	
	
	cv::waitKey(0);
	cv::destroyAllWindows();

}

void show6() {
	cv::Mat img1 = cv::Mat::zeros(512,512,CV_8UC1);
	
	uchar value=0;
	for(int i=0;i<img1.rows;i++) {
		for(int j=0;j<img1.cols;j++) {
			value++;
			img1.at<uchar>(i,j)=value;

		}
	}

	cv::namedWindow("Image1");
	cv::imshow("Image1",img1);

	cv::waitKey(0);
	cv::destroyAllWindows();

}

void  show7() {

	cv::Mat img1 = cv::imread("coins.png", cv::IMREAD_UNCHANGED);
	if(img1.empty()) {
		std::cerr << "파일이 없습니다." << std::endl;
		return;
	}

	std::cout << "이미지의 폭: " << img1.cols << std::endl;
	std::cout << "이미지의 높이: " << img1.rows << std::endl;
	std::cout << "이미지의 크기: " << img1.size() << std::endl;	
	std::cout << "픽셀 한 개의 사이즈: " << img1.elemSize() << std::endl;	
	std::cout << "이미지의 채널 수: " << img1.channels() << std::endl;
	std::cout << "이미지의 타입: " << img1.type() << std::endl;

	if(img1.type() == CV_8UC1) std::cout << "그레이 스케일" << std::endl;
	else if(img1.type() == CV_8UC3) std::cout << "컬러" << std::endl;
	else std::cout << "png" << std::endl;

}

void show8() {
	// float data[]={1.0f, 2.0f, 3.0f, 4.0f};
	// cv::Mat mat1(2,2,CV_32FC1, data); 	// [1 2]
	// 									// [3 4]
	// cv::Mat mat2=mat1.inv();
	// cv::Mat mat3=mat1*mat2; //

	// std::cout << mat1 << std::endl;
	// std::cout << mat2 << std::endl;
	// std::cout << mat3 << std::endl;

	uchar data2[]={1,2,3,4,5,6,7,8, 9, 10, 11, 12};
	cv::Mat mat4(3,4,CV_8UC1, data2);
	std::cout << mat4 << std::endl;
	mat4 = mat4.reshape(0, 4);
	std::cout << mat4 << std::endl;

	// cv::Mat img1 = cv::imread("lenna.png", cv::IMREAD_GRAYSCALE);
	// cv::namedWindow("Lenna");
	// cv::imshow("Lenna", img1.t()); //trans

	// cv::Mat img2 = img1-50;
	// cv::namedWindow("Lenna2");
	// cv::imshow("Lenna2", img2);

	// cv::waitKey(0);
	// cv::destroyAllWindows();
	

}

void show9() { //4*4 구해보자
	float data[][4]={
		{1.0f, 2.0f, 3.0f, 4.0f},
		{5.0f, 6.0f, 7.0f, 8.0f},
		{9.0f, 10.0f, 11.0f, 12.0f},
		{13.0f, 14.0f, 15.0f, 16.0f}
		};

	cv::Mat mat1(4,4,CV_32FC1, data); 	// [1 2]
										// [3 4]
	cv::Mat mat2=mat1.inv();
	cv::Mat mat3=mat1*mat2; //

	std::cout << mat1 << std::endl;
	std::cout << mat2 << std::endl;
	std::cout << mat3 << std::endl;

}