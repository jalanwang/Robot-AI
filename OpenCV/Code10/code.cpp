#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

//챕터 10. 컬러영상 다루기

// 색반전 1
void show1() {
    cv::Mat src=cv::imread("butterfly.jpg", cv::IMREAD_COLOR);

    if(src.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return;
    }

    cv::Mat dst(src.rows, src.cols, src.type());

    for(int j=0; j<src.rows; j++) {
        for(int i=0;i<src.cols;i++) {
            cv::Vec3b& pixel1=src.at<cv::Vec3b>(j, i);
            cv::Vec3b& pixel2=dst.at<cv::Vec3b>(j, i);

            pixel2[0]=255-pixel1[0];
            pixel2[1]=255-pixel1[1];
            pixel2[2]=255-pixel1[2];
        }
    }
   

    cv::imshow("src", src);
    cv::imshow("dst", dst);
    cv::waitKey();
    cv::destroyAllWindows();

    return;
}

// 색반전 2 cv::Scalar 사용
void show2() {
    cv::Mat src=cv::imread("butterfly.jpg", cv::IMREAD_COLOR);

    if(src.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return;
    }

    cv::Mat dst(src.rows, src.cols, src.type());
    dst = cv::Scalar::all(255) - src;

    cv::imshow("src", src);
    cv::imshow("dst", dst);
    cv::waitKey();
    cv::destroyAllWindows();

    return;
}


// 컬러영상을 cvtColor 함수를 이용, 그레이스케일 영상으로 변환
void show3() {

    cv::Mat src=cv::imread("butterfly.jpg", cv::IMREAD_COLOR);

    if(src.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return;
    }

    cv::Mat dst;

    cv::cvtColor(src, dst, cv::COLOR_BGR2GRAY);

    cv::imshow("src", src);
    cv::imshow("dst", dst);
    cv::waitKey();
    cv::destroyAllWindows();
    
    return;
}

// BGR 컬러영상에서 컬러별 채널 분리
void show4() {

    cv::Mat src=cv::imread("candies.png", cv::IMREAD_COLOR);

    if(src.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return;
    }

    std::vector<cv::Mat> bgr_planes;
    cv::split(src, bgr_planes);

    cv::imshow("src", src);
    cv::imshow("B channel", bgr_planes[0]);
    cv::imshow("G channel", bgr_planes[1]); 
    cv::imshow("R channel", bgr_planes[2]);
    cv::waitKey();
    cv::destroyAllWindows();

    return;
}

// BGR 컬러영상에서 컬러별 채널 분리. 그리고 분리된 채널로 컬러 영상 생성
void show5() {

    cv::Mat src=cv::imread("candies.png", cv::IMREAD_COLOR);

    if(src.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return;
    }

    std::vector<cv::Mat> bgr_planes;
    cv::split(src, bgr_planes);

    cv::imshow("src", src);
    cv::imshow("B channel", bgr_planes[0]);
    cv::imshow("G channel", bgr_planes[1]); 
    cv::imshow("R channel", bgr_planes[2]);


    cv::Mat dst1, dst2, dst3;

    // cv::merge를 사용하여 채널 합치기 (빈 채널은 0으로 채움)
    cv::Mat empty = cv::Mat::zeros(src.size(), CV_8UC1);
    cv::merge(std::vector<cv::Mat>{bgr_planes[0], empty, empty}, dst1);
    cv::merge(std::vector<cv::Mat>{empty, bgr_planes[1], empty}, dst2);
    cv::merge(std::vector<cv::Mat>{empty, empty, bgr_planes[2]}, dst3);

    cv::imshow("B channel color", dst1);
    cv::imshow("G channel color", dst2);
    cv::imshow("R channel color", dst3);

    cv::waitKey();
    cv::destroyAllWindows();

    return;
}


// 컬럼 이미지의 히스토그램을 구하고 평활화 한후 이미지 출력하는 일반적인 방법
void show6() {
    cv::Mat src=cv::imread("pepper.bmp", cv::IMREAD_COLOR);

    if(src.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return;
    }

    cv::Mat dst;
    cv::cvtColor(src, dst, cv::COLOR_BGR2YCrCb);

    std::vector<cv::Mat> ycrcb_planes;
    cv::split(dst, ycrcb_planes);

    cv::equalizeHist(ycrcb_planes[0], ycrcb_planes[0]);

    cv::merge(ycrcb_planes, dst);
    cv::cvtColor(dst, dst, cv::COLOR_YCrCb2BGR);

    cv::imshow("src", src);
    cv::imshow("dst", dst);
    cv::waitKey();
    cv::destroyAllWindows();
    return;
}


// HSV 컬러영상에서 특정 색상 영역을 추출하는 마스크 영상 생성
int lower_hue=40;
int upper_hue=80;

cv::Mat src, src_hsv, mask;

void on_hue_changed(int, void*) {
    cv::Scalar lowerb(lower_hue, 100, 0);
    cv::Scalar upperb(upper_hue, 255, 255);
    cv::inRange(src_hsv, lowerb, upperb, mask); // 조건 검사 후 특정값 반환

    cv::imshow("mask", mask);
}

void show7() {    
    src=cv::imread("candies.png", cv::IMREAD_COLOR);
    if(src.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return;
    }
    cv::cvtColor(src, src_hsv, cv::COLOR_BGR2HSV);

    cv::imshow("src", src);
    cv::namedWindow("mask");
    cv::createTrackbar("Lower Hue", "mask", &lower_hue, 179, on_hue_changed);
    cv::createTrackbar("Upper Hue", "mask", &upper_hue, 179, on_hue_changed);
    on_hue_changed(0, 0); //초기화 콜백 호출
    
    cv::waitKey();
    cv::destroyAllWindows();    
    
    return;
}

// 히스토그램 역투영을 이용한 피부색 영역 검출
void show8() {
    cv::Mat ref, ref_ycrcb, mask;
    ref=cv::imread("ref.png", cv::IMREAD_COLOR);
    mask=cv::imread("mask.bmp", cv::IMREAD_GRAYSCALE);
    cv::cvtColor(ref, ref_ycrcb, cv::COLOR_BGR2YCrCb);

    cv::Mat hist;
    int channels[]={1,2};
    int cr_bins=128;
    int cb_bins=128;
    int histSize[]={cr_bins, cr_bins};
    float cr_ranges[]={0,256};
    float cb_ranges[]={0,256};
    const float* ranges[]={cr_ranges, cb_ranges};

    cv::calcHist(&ref_ycrcb, 1, channels, mask, hist, 2, histSize, ranges); 

    // 히스토그램 역투영
    cv::Mat src, src_ycrcb;
    src=cv::imread("kids.png", cv::IMREAD_COLOR);
    cv::cvtColor(src, src_ycrcb, cv::COLOR_BGR2YCrCb);

    cv::Mat backproj;
    cv::calcBackProject(&src_ycrcb, 1, channels, hist, backproj, ranges, 1, true);

    cv::imshow("src", src);
    cv::imshow("backproj", backproj);

    cv::waitKey();
    cv::destroyAllWindows();

    return;
}