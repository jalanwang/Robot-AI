#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

//챕터 11. 이진화

//트랙바를 이용한 이진화
void on_threshold(int pos, void* userdata) {
    cv::Mat src= *(cv::Mat*)userdata;
    cv::Mat dst;
    cv::threshold(src, dst, pos, 255, cv::THRESH_BINARY);
    cv::imshow("Binary Image", dst);   
}

void show1() {
    cv::Mat src = cv::imread("neutrophils.png", cv::IMREAD_GRAYSCALE);
    if (src.empty()) {
        std::cout << "Could not open or find the image!" << std::endl;
        return;
    }

    cv::imshow("Original Image", src);

    cv::namedWindow("dst");
    int threshold_value = 128;
    cv::createTrackbar("Threshold", "dst", nullptr, 255, on_threshold, (void*)&src);
    on_threshold(threshold_value, &src);
    cv::setTrackbarPos("Threshold", "dst", threshold_value);

    cv::waitKey(0);

    return;
}



// 적응형 이진화 with 트랙바
void on_trackbar(int pos, void* userdata) {
    cv::Mat src= *(cv::Mat*)userdata;
    
    int bsize = pos;
    if (bsize % 2 == 0) bsize--; //블록 크기는 홀수여야 함
    if (bsize < 3) bsize = 3; //최소 블록 크기 3
    if (bsize > 255) bsize = 255; //최대 블록 크기 255
    cv::Mat dst;
    cv::adaptiveThreshold(src, dst, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, bsize, 5);    cv::imshow("Binary Image", dst);   

    cv::imshow("Binary Image", dst);
}

void show2() {
    cv::Mat src = cv::imread("sudoku.jpg", cv::IMREAD_GRAYSCALE);
    if (src.empty()) {
        std::cout << "Could not open or find the image!" << std::endl;
        return;
    }

    cv::imshow("Original Image", src);

    cv::namedWindow("dst");
    int block_size = 11;
    int threshold_value28;
    cv::createTrackbar("Block Size", "dst", nullptr, 200, on_trackbar, (void*)&src);    
    cv::setTrackbarPos("Block Size", "dst", block_size);

    cv::waitKey(0);

    return;
}