#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

void show1() {
    //saturatecast 테스트
    cv::Mat src = cv::imread("lenna.bmp", cv::IMREAD_GRAYSCALE);
    if (src.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return;
    }
    cv::Mat dst = src-100; // overflow 발생;
    
    cv::Mat dst2(512,512, CV_8UC1);
    for(int i=0; i<dst2.rows; i++) {
        for(int j=0; j<dst2.cols; j++) {
            dst2.at<uchar>(i,j) = src.at<uchar>(i,j)+100;
        }
    }
    cv::imshow("src", src);
    cv::imshow("dst", dst);
    cv::imshow("dst2", dst2);   
        
    cv::waitKey();
    cv::destroyAllWindows();
    
    return;
}

void on_brightness_changed(int level, void* userdata)
{
    cv::Mat *img = (cv::Mat*)userdata;

    img->convertTo(*img, -1, 1, level);
    cv::imshow("Canvas", *img);
    return;
}

void show2() { //track bar
    cv::Mat src = cv::imread("lenna.bmp", cv::IMREAD_GRAYSCALE);

    cv::namedWindow("Canvas", cv::WINDOW_AUTOSIZE);
    cv::imshow("Canvas", src);

    cv::createTrackbar("Brightness", "Canvas", 0, 100, on_brightness_changed, (void*)&src);
    
    
    cv::waitKey(0);     
    cv::destroyAllWindows();

    return;
}

void show3() { //contrast
    cv::Mat src = cv::imread("lenna.bmp", cv::IMREAD_GRAYSCALE);
    if(src.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return;
    }

    float alpha=1.0f;
    cv::Mat dst=(1+alpha)*src- alpha*128;
    
    imshow("src", src);
    imshow("dst", dst);  
    
    cv::waitKey(0);     
    cv::destroyAllWindows();

    return;
}

void show4() { //히스토그램
    std::cout << "Current function: " << __func__ << std::endl;
    
    cv::Mat src = cv::imread("hawkes.bmp", cv::IMREAD_GRAYSCALE);
    if(src.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return;
    }

    double min=0;
    double max=0;
    cv::minMaxLoc(src, &min, &max); // 최소, 최대값 찾기

    cv::Mat dst= (src-min)*255/(max-min);    
    imshow("src", src);
    imshow("dst", dst);  
    
    cv::waitKey(0);     
    cv::destroyAllWindows();

    return;
}

