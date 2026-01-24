#include "opencv2/opencv.hpp"
#include <iostream>

void show0_1() {
	cv::Mat img1;

	cv::Mat img2(480, 640, CV_8UC1);
	cv::Mat img3(480, 640, CV_8UC3);
	cv::Mat img4(cv::Size(640, 480), CV_8UC3);
	
	cv::namedWindow("Image2");
	cv::imshow("Image2", img2);
	cv::namedWindow("Image3");
	cv::imshow("Image3", img3);
	cv::namedWindow("Image4");
	cv::imshow("Image4", img4);

	cv::waitKey(0);
	cv::destroyAllWindows();	
}

void show0_2() { // Scalar 클래스 사용
	cv::Mat img5(480, 640, CV_8UC1, cv::Scalar(128));
	cv::Mat img6(480, 640, CV_8UC3, cv::Scalar(255,0,0));

	cv::imshow("Image5", img5);
	cv::imshow("Image6", img6);

	cv::waitKey(0);
	cv::destroyAllWindows();	
}

void show0_3() { // 초깃값 설정함수
	cv::Mat mat1 = cv::Mat::zeros(3,3,CV_32SC1);
	cv::Mat mat2 = cv::Mat::ones(3,3,CV_32FC1);
	cv::Mat mat3 = cv::Mat::eye(3,3,CV_32FC1);

	std::cout << mat1 << std::endl;
	std::cout << mat2 << std::endl;
	std::cout << mat3 << std::endl;
}

// 어레이, 콤마, 브라킷을 이용한 데이타 삽입
// create() 메소드를 이용한 메모리 재할당
void show0_4() { 

	float data[]={1,2,3,4,5,6};
	cv::Mat mat4(2,3,CV_32FC1, data); 

	cv::Mat mat5=(cv::Mat_<float>(2,3) << 1,2,3,4,5,6);
	cv::Mat mat6=cv::Mat_<uchar>({2,3}, {1,2,3,4,5,6});

	std::cout << mat4 << std::endl;
	std::cout << mat5 << std::endl;
	std::cout << mat6 << std::endl;

	mat4.create(4,4, CV_8UC3); // 메모리 재할당 
	mat5.create(4,4, CV_32FC1); // 메모리 재할당

	std::cout << mat4 << std::endl;
	std::cout << mat5 << std::endl;

	mat4 = cv::Scalar(255,0,0); // blue color
	mat5.setTo(1.0f);	

	std::cout << mat4 << std::endl;
	std::cout << mat5 << std::endl;

}

// 이미지 읽기 및 정보 출력
void show1() {

cv::Mat image1 = cv::imread("lenna.bmp");
cv::Mat image2 = cv::imread("dog.bmp");
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

 //스칼라 클래스 사용 연습
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

// 스태밍 함수 사용
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
 // clone() 메소드를 이용한 복사
 // copyTo() 메소드를 이용한 복사
 // 단순 대입을 이용한 복사. 얕은 복사, 참조 복사
void show4() {
	
	cv::Mat imgDog= cv::imread("dog.bmp");

	if(imgDog.empty()) {
		std::cerr << "파일이 없습니다." << std::endl;
		return;
	}

	cv::namedWindow("Dog");
	cv::imshow("Dog", imgDog);

	cv::Mat imgClonedDog = imgDog.clone(); 

	cv::Mat copiedDog;	
	imgDog.copyTo(copiedDog); // copied dog

	cv::Mat shallowCopiedDog = imgDog; //shallow copy
	
	cv::namedWindow("Cloned Dog");
	cv::imshow("Cloned Dog", imgClonedDog);

	cv::namedWindow("Copied Dog");
	cv::imshow("Copied Dog", copiedDog);
	
	cv::namedWindow("Shallowed Copied Dog");
	cv::imshow("Shallowed Copied Dog", shallowCopiedDog);

	imgDog.setTo(cv::Scalar(0, 255, 255)); // yellow color	
	cv::namedWindow("Dog after setTo");
	cv::imshow("Dog after setTo", imgDog);

	cv::namedWindow("Shallowed Copied Dog after setTo");
	cv::imshow("Shallowed Copied Dog after setTo", shallowCopiedDog);


	cv::waitKey(0);
	cv::destroyAllWindows();
}

// 부분 반전, 부분 복사
void show5_0() {
	cv::Mat imgCat = cv::imread("cat.bmp");
	cv::Mat notCat = ~imgCat;
	cv::Mat windowImg = imgCat(cv::Rect(220, 120, 340, 240)); // 영역을 분할하라는 명령어	

	cv::imread("Cat", imgCat);
	cv::namedWindow("Cat");
	cv::imshow("Cat", imgCat);	

	cv::namedWindow("~Cat");
	cv::imshow("~Cat", notCat);	

	cv::namedWindow("Region of Cat");
	cv::imshow("Region of Cat", windowImg);	
	
	cv::waitKey(0);
	cv::destroyAllWindows();
}

// 부분 반전, 부분 복사, 원본 변경시 clone 복사에 영향 없는지 확인
void show5_1() {
	cv::Mat imgCat = cv::imread("cat.bmp");
	if(imgCat.empty()) {
		std::cerr << "파일이 없습니다." << std::endl;
		return;
	}

	cv::Mat windowImg = imgCat(cv::Rect(220, 120, 340, 240)); // 영역을 분할하라는 명령어
	cv::Mat windowImgCloned = windowImg.clone(); // 영역을 복사하라는 명령어

	windowImg= ~windowImg; // 부분 반전

	cv::imshow("Image Cat", imgCat);
	cv::imshow("Window Image Cat", windowImg);	
	cv::imshow("Window Image Cloned Cat", windowImgCloned);
	
	cv::waitKey(0);
	cv::destroyAllWindows();
}


// Mat::at<>() 메소드 사용법
// 행렬의 원소값 참조 방법 중 첫 번째
void show6_0() {
	cv::Mat img1 = cv::Mat::zeros(256,256,CV_8UC1);
	
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

// Mat::ptr<>() 포인터를 이용하는 법
// 행렬의 원소값 참조 방법 중 두 번째
void show6_1() {
	cv::Mat img1 = cv::Mat::zeros(256,256,CV_8UC1);
	
	
	for(int j=0;j<img1.rows;j++) {
		uchar* p = img1.ptr<uchar>(j);
		for(int i=0;i<img1.cols;i++) {
			
			//p[i]++; // 교재가 잘못됨.
			p[i]=j; // 행 번호로 값 설정
			// p[i]=i; // 열 번호로 값 설정
		}
	}

	cv::namedWindow("Image1");
	cv::imshow("Image1",img1);

	cv::waitKey(0);
	cv::destroyAllWindows();

}

// Mat::Iterrator_<>를 이용하는 법
// 행렬의 원소값 참조 방법 중 세 번째
void show6_2() {
	cv::Mat img1 = cv::Mat::zeros(256,256,CV_8UC1);	
	
	for(cv::MatIterator_<uchar> it=img1.begin<uchar>();it!=img1.end<uchar>();it++) {
		//*it=128;
		*it=it.pos().y; // 행 번호로 값 설정
		// *it=it.pos().x; // 열 번호로 값 설정
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