#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

//챕터 8. Affine Transformations and 투시 변환

// [1 0; [x; + [a;
//  0 1]   y]    b]
// 같은 행렬은 아래와 같다.
// [1 0 a;  [x;
//  0 1 b]   y]


void show1() {
    cv::Mat src=cv::imread("tekapo.bmp");
    cv::imshow("src", src);

    cv::Point2f srcPts[3], dstPts[3];

    srcPts[0]=cv::Point2f(0,0);
    srcPts[1]=cv::Point2f(src.cols-1,0);
    srcPts[2]=cv::Point2f(src.cols-1, src.rows-1);

    dstPts[0]=cv::Point2f(0,0);
    dstPts[1]=cv::Point2f(src.cols-100, 100);
    dstPts[2]=cv::Point2f(src.cols-50, src.rows -50);

    cv::Mat move = cv::getAffineTransform(srcPts, dstPts);

    cv::Mat dst;
    warpAffine(src, dst, move, cv::Size());
    
    cv::imshow("dst", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return;
}

void show2() {
    cv::Mat src=cv::imread("tekapo.bmp");
    cv::imshow("src", src);

    cv::Mat dst;
    
    cv::Mat move = cv::Mat_<float>({2,3}, {1.f, 0.f, 150.f, 0.f, 1.f, 100.f});
    std::cout<<move<<std::endl;
    warpAffine(src, dst, move, cv::Size());

    cv::imshow("dst", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return;
}

//기울이기 shear
void show3() {
    cv::Mat src=cv::imread("tekapo.bmp");
    cv::imshow("src", src);

    cv::Mat dst;
    
    float declineX=0.0f, declineY=0.0f;
    std::cout << "Enter declineX %: " << std::endl;
    std::cin >> declineX;
    std::cout << "Enter declineY %: " << std::endl;
    std::cin >> declineY;

    cv::Mat move = cv::Mat_<float>({2,3}, {1.f, declineX, 0.f,
                                           declineY, 1.f, 0.f});
    std::cout<<move<<std::endl;  
    
    warpAffine(src, dst, move, cv::Size(cv::Size(cvRound(src.cols+src.rows*declineX), src.rows+src.cols*declineY)));

    cv::imshow("dst", dst);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return;
}

//확대 축소
void show4() {
    cv::Mat src=cv::imread("tekapo.bmp");
    cv::imshow("src", src);

    cv::Mat dst;
    
    float zoom;
    std::cout << "Enter % ZoomIN/OUT: " << std::endl;
    std::cin >> zoom;    

    cv::Mat move = cv::Mat_<float>({2,3}, {zoom, 0.f, 0.f,
                                           0.f, zoom, 0.f}); //확대 축소 행렬
    std::cout<<move<<std::endl;  
    
    warpAffine(src, dst, move, cv::Size(cvRound(src.cols*zoom), cvRound(src.rows*zoom)));

    cv::imshow("dst", dst);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return;
}

//부분 확대 축소
void show5() {
    cv::Mat src=cv::imread("rose.bmp");
    

    cv::Mat dst1, dst2, dst3, dst4;

    cv::resize(src, dst1, cv::Size(), 4, 4, cv::INTER_NEAREST);
    cv::resize(src, dst2, cv::Size(1920, 1280));
    cv::resize(src, dst3, cv::Size(1920, 1280), 0, 0, cv::INTER_CUBIC);
    cv::resize(src, dst4, cv::Size(1920, 1280), 0, 0, cv::INTER_LANCZOS4);

    
    cv::imshow("src", src);
    cv::imshow("dst1 - INTER_NEAREST", dst1(cv::Rect(400, 500, 400, 400)));
    cv::imshow("dst2 - INTER_LINEAR", dst2(cv::Rect(400, 500, 400, 400)));
    cv::imshow("dst3 - INTER_CUBIC", dst3(cv::Rect(400, 500, 400, 400)));
    cv::imshow("dst4 - INTER_LANCZOS4", dst4(cv::Rect(400, 500, 400, 400)));


    cv::waitKey(0);
    cv::destroyAllWindows();

    return;
}


//회전
void show6() {
    cv::Mat src=cv::imread("tekapo.bmp");
    
    cv::imshow("src", src);
    cv::Mat dst;

    cv::Point2f center(src.cols/2.f, src.rows/2.f);
    cv::Mat m = cv::getRotationMatrix2D(center, 30.f, 0.5f);
    warpAffine(src, dst, m, cv::Size());

    cv::imshow("dst", dst); //30도 회전

    cv::waitKey(0);
    cv::destroyAllWindows();

    return;
}

// flip
void show7() {
    cv::Mat src=cv::imread("eastsea.bmp");
    
    cv::imshow("src", src);
    cv::Mat dst;
    
    int flipCode[3] = {1, 0, -1};
    for(int i=0; i<3; i++) {
        cv::flip(src, dst, flipCode[i]);
        cv::imshow("dst"+std::to_string(i), dst);
    }

    cv::waitKey(0);
    cv::destroyAllWindows();

    return;
}

cv::Mat src;
cv::Point2f srcQuad[4], dstQuad[4];
//show8과 연동
void on_mouse(int event, int x, int y, int flags, void* userdata) {
    static int cnt; //default 0
    if(event == cv::EVENT_LBUTTONDOWN) {
        if(cnt < 4) {
        srcQuad[cnt++]=cv::Point2f((float)x, (float)y);

        cv::circle(src, cv::Point(x,y), 0, cv::Scalar(0,255,0), -1);
        cv::imshow("src", src);

            if(cnt == 4) {
                int width=200, height=300;
                dstQuad[0]=cv::Point2f(0,0);
                dstQuad[1]=cv::Point2f((float)width-1,0);
                dstQuad[2]=cv::Point2f((float)width-1, (float)height-1);
                dstQuad[3]=cv::Point2f(0, (float)height-1);

                cv::Mat pers = cv::getPerspectiveTransform(srcQuad, dstQuad);

                cv::Mat dst;
                cv::warpPerspective(src, dst, pers, cv::Size(width, height));
                cv::imshow("dst", dst);
            }
        }               
    }
}


// perspective transform
void show8() {
    
    src=cv::imread("card.bmp");
    
    cv::namedWindow("src");
    cv::setMouseCallback("src", on_mouse);
        
    cv::imshow("src", src);
    cv::waitKey();
    
    cv::destroyAllWindows();

    return;
}