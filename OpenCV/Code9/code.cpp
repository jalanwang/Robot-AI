#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

//챕터 9. 에지검출, 선과 원.


void show1() {
    cv::Mat src=cv::imread("lenna.bmp", cv::IMREAD_GRAYSCALE);
    
    cv::Mat dx, dy;

    cv::Sobel(src, dx, CV_32FC1, 1, 0);
    cv::Sobel(src, dy, CV_32FC1, 0, 1);

    cv::Mat mag; //크기를 볼 Matrix //

    cv::magnitude(dx, dy, mag); //
    mag.convertTo(mag, CV_8UC1); //8비트로 변환

    //cv::Mat edge = mag > 150;
    cv::Mat edge = mag > 150;

    //cv::imshow("dx", dx);
    //cv::imshow("dy", dy);
    
    cv::imshow("src", src);
    cv::imshow("magnitude", mag);
    cv::imshow("edge", edge);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return;
}

void show2() { //캐니 에지 검출기
    cv::Mat src=cv::imread("lenna.bmp", cv::IMREAD_GRAYSCALE);
    
    cv::Mat dst1, dst2;;

    cv::Canny(src, dst1, 50, 100);
    cv::Canny(src, dst2, 50, 150);

    cv::imshow("src", src);
    cv::imshow("dst1", dst1);
    cv::imshow("dst2", dst2);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return;
}

void show3() { //직선 검출기
    cv::Mat src=cv::imread("building.jpg", cv::IMREAD_GRAYSCALE);
    
    cv::Mat edge;

    cv::Canny(src, edge, 50, 100);
    std::vector<cv::Vec2f> lines;
    cv::HoughLines(edge, lines, 1.0f, CV_PI/180, 250);
    //cv::HoughLinesP(edge, lines, 1.0f, CV_PI/180, 250, 5.0f, 10.0f);

    cv::Mat dst;
    cv::cvtColor(edge, dst, cv::COLOR_GRAY2BGR);

    for(int i=0; i< lines.size(); i++) {
         std::cout << i << lines[i][0] << ", " << lines[i][1] << std::endl;
    }
    
    cv::imshow("src", src);

    for(size_t i=0;i<lines.size(); i++) {
        float rho = lines[i][0];
        float theta = lines[i][1];

        double cos_t=cos(theta);
        double sin_t=sin(theta);
        double x0=rho*cos_t;
        double y0=rho*sin_t;    
        double alpha=1000;
        
        cv::Point pt1(cvRound(x0 + alpha*(-sin_t)), cvRound(y0 + alpha*(cos_t)));
        cv::Point pt2(cvRound(x0 - alpha*(-sin_t)), cvRound(y0 - alpha*(cos_t)));

        cv::line(dst, pt1, pt2, cv::Scalar(0,0,255),15, cv::LINE_AA);
    }

    cv::imshow("dst", dst);
    cv::imshow("edge", edge);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return;
}

void show4() {
    cv::Mat src=cv::imread("coins3.jpg", cv::IMREAD_GRAYSCALE);

    cv::Mat blurred;
    cv::blur(src, blurred, cv::Size(3,3));

    cv::Mat canny;
    cv::Canny(blurred, canny, 150, 100);
    cv::imshow("cannyed", canny);

    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(blurred, circles, cv::HOUGH_GRADIENT, 1, 50, 240, 30, 15, 30);

    cv::Mat dst;
    cv::cvtColor(src, dst, cv::COLOR_GRAY2BGR);

    for(cv::Vec3f c:circles) {
        cv::Point center(cvRound(c[0]), cvRound(c[1]));
        int radius = cvRound(c[2]);
        cv::circle(dst, center, radius, cv::Scalar(0,0,255), 3, cv::LINE_AA);
    }
    cv::imshow("src", src);
    cv::imshow("dst", dst);
    cv::waitKey(0);
    cv::destroyAllWindows();

}