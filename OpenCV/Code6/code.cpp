#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

void show1() {
    cv::Mat img1 = cv::imread("lenna256.bmp", cv::IMREAD_GRAYSCALE);
    cv::Mat img2 = cv::imread("square.bmp", cv::IMREAD_GRAYSCALE);

    cv::Mat img3 = img1 + img2; // 행렬 덧셈
    cv::Mat img4 = img1 - img2; // 행렬 뺄셈
    cv::imshow("Image 1", img1);
    cv::imshow("Image 2", img2);
    cv::imshow("Image 3 - Addition", img3);
    cv::imshow("Image 4 - Subtraction", img4);

    cv::Mat dst3(256,256, CV_8UC1);
    cv::Mat dst4(256,256, CV_8UC1);

    for(int i=0; i<img1.rows; i++) {
        for(int j=0; j<img1.cols; j++) {
            dst3.at<uchar>(i,j) = cv::saturate_cast<uchar>(img1.at<uchar>(i,j) + img2.at<uchar>(i,j));
            dst4.at<uchar>(i,j) = cv::saturate_cast<uchar>(img1.at<uchar>(i,j) - img2.at<uchar>(i,j));
        }
    }

    cv::imshow("Image 5 - Addition (Manual)", dst3);
    cv::imshow("Image 6 - Subtraction (Manual)", dst4);


    cv::waitKey(0);
    cv::destroyAllWindows();

    return;
}

void show2() {
    cv::Mat img1 = cv::imread("scene1.png", cv::IMREAD_GRAYSCALE);
    cv::Mat img2 = cv::imread("scene2.png", cv::IMREAD_GRAYSCALE);

    cv::Mat dst1;
    cv::Mat dst2;
    cv::Mat dst3;

    cv::add(img1, img2, dst1);
    cv::subtract(img1, img2, dst2); // 물체를 움직일 때, 경계 검출 등에 유용
    cv::absdiff(img1, img2, dst3); // 물체를 움직일 때, 경계 검출 등에 가장 유용

    cv::imshow("Image 5 - Sub", dst2);
    cv::imshow("Image 6 - Abs(Sub()", dst3);


    cv::waitKey(0);
    cv::destroyAllWindows();

    return;

}