#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat img = cv::Mat::zeros(480, 640, CV_8UC3);
    cv::circle(img, cv::Point(320, 240), 100, cv::Scalar(0, 255, 255), 3);
    cv::putText(img, "OpenCV Success!", cv::Point(150, 250), cv::FONT_HERSHEY_SIMPLEX, 1.2, cv::Scalar(255, 255, 255), 2);

    cv::imshow("Display Window", img); // 화면에 창 띄우기
    cv::waitKey(0);                   // 아무 키나 누를 때까지 대기
    
    return 0;
}