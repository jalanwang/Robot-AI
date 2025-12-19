#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    std::cout << "Hello World" << std::cout;
    
    cv::Mat img;
    img=cv::imread("lenna.png");

 

    cv::imshow("Lenna Window", img); // 화면에 창 띄우기
    cv::waitKey(0);                   // 아무 키나 누를 때까지 대기
    cv::
    
    
    return 0;
}