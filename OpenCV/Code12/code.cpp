#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

//챕터 12. 레이블링

void show1() {
    uchar data[] = {
        0,0,1,1,0,0,0,0,
        1,1,1,1,0,0,1,0,
        1,1,1,1,0,0,0,0,
        0,0,0,0,0,1,1,0,
        0,0,0,1,1,1,1,0,
        0,0,0,1,0,0,1,0,
        0,0,1,1,1,1,1,0,
        0,0,0,0,0,0,0,0,
    };

    cv::Mat src=cv::Mat(8,8,CV_8UC1, data)*255;
    cv::Mat labels;

    int cnt=connectedComponents(src, labels);

    std::cout << "src:\n" << src << std::endl;
    std::cout << "labels:\n" << labels << std::endl;
    std::cout << "number of labels:" << cnt << std::endl;

    return;
}

void show2() {
    cv::Mat src=cv::imread("keyboard.bmp", cv::IMREAD_GRAYSCALE);

    if(src.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return;
    }

    cv::Mat bin;
    cv::threshold(src, bin, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

    cv::Mat labels, stats, centroids;

    int cnt = cv::connectedComponentsWithStats(bin, labels, stats, centroids);

    cv::Mat dst;
    cv::cvtColor(src, dst, cv::COLOR_GRAY2BGR);

    for(int i=1;i<cnt;i++) {
        int* p = stats.ptr<int>(i);

        if(p[4]<20) continue;

        cv::rectangle(dst, cv::Rect(p[0], p[1], p[2], p[3]),
                      cv::Scalar(0, 255,255), 2);
    }
    cv::imshow("src", src);
    cv::imshow("dst", dst);
    cv::waitKey();  

    cv::destroyAllWindows();

    return;
}

void show3() {
    cv::Mat src=cv::imread("contours.bmp", cv::IMREAD_GRAYSCALE);

    if(src.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return;
    }

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    cv::findContours(src, contours, hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_NONE);

    cv::Mat dst;
    cv::cvtColor(src, dst, cv::COLOR_GRAY2BGR);

    for(int idx=0; idx>=0; idx=hierarchy[idx][0]) {
        cv::Scalar c(rand() & 255, rand() & 255, rand() & 255);
        cv::drawContours(dst, contours, idx, c, -1, cv::LINE_8, hierarchy);        
    }   
    cv::imshow("src", src);
    cv::imshow("dst", dst);
    cv::waitKey();  

    cv::destroyAllWindows();

    return;
}


void setlabel(cv::Mat& img, const std::vector<cv::Point>& pts, const cv::String& label) {
    cv::Rect rc=boundingRect(pts);
    cv::rectangle(img, rc, cv::Scalar(0,0,255),1);
    cv::putText(img, label, rc.tl(), cv::FONT_HERSHEY_SIMPLEX, 1,
                cv::Scalar(0,0,255));

    return;
}
void show4() {
    cv::Mat img=cv::imread("polygon.bmp", cv::IMREAD_COLOR);
    if(img.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return;        
    }

    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    cv::Mat bin;
    cv::threshold(gray, bin, 200, 255, cv::THRESH_BINARY_INV | cv::THRESH_OTSU);

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(bin, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);


    for(std::vector<cv::Point>& pts : contours) {
        if(cv::contourArea(pts)<400)
            continue;

        std::vector<cv::Point> approx;
        cv::approxPolyDP(pts, approx, cv::arcLength(pts, true)*0.02, true);

        int vtc = (int)approx.size();

        if(vtc==3)
            setlabel(img, pts, "TRI");
        else if(vtc==4)
            setlabel(img, pts, "RECT");
        else if(vtc>4) {
            double len=cv::arcLength(pts, true);
            double area=cv::contourArea(pts);
            double ratio = 4. * CV_PI*area/(len*len);
            
            if(ratio >0.8) {
                setlabel(img, pts, "CIR");
            }
        }        
    }
    cv::imshow("img", img);
    cv::waitKey();  

    cv::destroyAllWindows();
    return;
}