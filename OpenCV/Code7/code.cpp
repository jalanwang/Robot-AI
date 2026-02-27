#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

void show1() {
    float filter_data[]={-1.f, -1.f,0.f,-1.f, 0.f, 1.f, 0.f, 1.f, 1.f};   

    cv::Mat emboass(3,3, CV_32FC1, filter_data); // float형 1채널 행렬 생성
    std::cout << "Emboass Kernel: \n" << emboass << std::endl;    

    cv::Mat dst;
    cv::Mat src = cv::imread("rose.bmp");
    cv::filter2D(src, dst, -1,  emboass, cv::Point(-1,-1), 80, cv::BORDER_DEFAULT);

    cv::imshow("Source", src);
    cv::imshow("Emboass Filter", dst); 

    cv::waitKey(0);
    cv::destroyAllWindows();

    return;
}

void show2() {
    float filter_data[]={1/9.f, 1/9.f, 1/9.f, 1/9.f, 1/9.f, 1/9.f, 1/9.f, 1/9.f, 1/9.f};   
    cv::Mat src = cv::imread("rose.bmp");

    cv::Mat blurr(3,3, CV_32FC1, filter_data); // float형 1채널 행렬 생성
    std::cout << "Blurrring Kernel: \n" << blurr << std::endl;    

    cv::Mat dst;

    cv::Mat blur(3,3, CV_32FC1, filter_data); // float형 1채널 행렬 생성
    cv::filter2D(src, dst, -1,  blur, cv::Point(-1,-1), 0);

    cv::imshow("Source", src);
    cv::imshow("Blurring Filter", dst); 

    cv::Mat blur2;
    cv::blur(src, blur2, cv::Size(3,3));
    cv::imshow("Blurring - Built-in", blur2);

        cv::waitKey(0);
    cv::destroyAllWindows();

    return;
}

void show3() {
    
    // for문의 실행 순서:
    // 1. 초기화 (int i=0) -> 최초 1회만 실행
    // 2. 조건 검사 (i<3) -> 참이면 루프 내부 실행, 거짓이면 종료
    // 3. 루프 내부 실행 (std::cout ...)
    // 4. 증감식 실행 (i++ 또는 ++i) -> 루프 내부 실행이 끝난 후 실행됨
    // 5. 2번으로 돌아가서 반복

    // i++ (후위 증가):
    // 루프 본문 실행이 끝난 뒤, 'i를 1 증가시키는 연산'을 수행하고 조건식(i<3)으로 돌아갑니다.
    for(int i=0;i<3;i++) {
        std::cout << "Hello OpenCV " << i << std::endl;
    }

    // ++i (전위 증가):
    // 역시 루프 본문 실행 뒤, 'i를 1 증가시키는 연산'을 수행하고 조건식으로 돌아갑니다.
    // 즉, 증감식 위치에서는 "연산을 실행하고 다시 루프의 시작(조건 검사)으로 돌아간다"는 흐름이 핵심입니다.
    // 따라서 i++이든 ++i든 i가 1 증가한다는 동작은 동일하게 수행됩니다.
    for(int i=0;i<3;++i) {
        std::cout << "Hello OpenCV " << i << std::endl;
    }
    return;
}

void show4() {
    cv::Mat src=cv::imread("rose.bmp", cv::IMREAD_GRAYSCALE);
    cv::imshow("SRC", src);

    cv::Mat dst;

    for(int sigma=1;sigma<=5;sigma++) {
        
        cv::GaussianBlur(src, dst, cv::Size(), sigma);
        cv::putText(dst, cv::format("Sigma: %d", sigma),
            cv::Point(10,30), cv::FONT_HERSHEY_SIMPLEX,1.0, cv::Scalar(255),1, cv::LINE_AA);
        
        cv::imshow("Gaussian Blur - Sigma " + std::to_string(sigma), dst);
    }

    cv::waitKey(0);
    cv::destroyAllWindows();

    return;
}

void show5() {
    
    cv::Mat src{cv::imread("rose.bmp", cv::IMREAD_GRAYSCALE)};
    //uniform initialization 문법을 사용하여 src 행렬을 생성합니다.

    cv::imshow("SRC", src);

    cv::Mat dst;

    for(int sigma=1;sigma<=10;sigma++) {
        
        cv::GaussianBlur(src, dst, cv::Size(), sigma);
        cv::putText(dst, cv::format("Sigma: %d", sigma), 
            cv::Point(10,30), cv::FONT_HERSHEY_SIMPLEX,1.0, cv::Scalar(255),1, cv::LINE_AA);        
        
        cv::imshow("Sharpend after Gausian Blur" + std::to_string(sigma), 2*src-dst);
        //cv::Mat dst = (1+alpha)*src-(alpha*blurred);

    }
    cv::waitKey(0);
    cv::destroyAllWindows();


return;
}


void show6() { //가우시안 노이즈
    
    cv::Mat src{cv::imread("lenna.bmp", cv::IMREAD_GRAYSCALE)};
    cv::imshow("SRC", src);



    for(int sigma=10;sigma<=30;sigma+=10) {
        
        cv::Mat noise(src.size(), CV_32SC1); //noise 행렬 생성
        cv::randn(noise, 0, sigma);
        cv::Mat dst;
        cv::add(src, noise, dst, cv::noArray(), CV_8UC1); //노이즈 추가
        cv::putText(dst, cv::format("Sigma: %d", sigma), 
            
        cv::Point(10,30), cv::FONT_HERSHEY_SIMPLEX,1.0, cv::Scalar(255),1, cv::LINE_AA);       
        cv::imshow("Added Gaussian Noise", dst);
        cv::waitKey(0); 
    }
  
    cv::destroyAllWindows();

return;
}

//양방향 필터
void show7()
{ 
    cv::Mat src{cv::imread("lenna.bmp", cv::IMREAD_GRAYSCALE)};
    cv::imshow("SRC", src);
   
    cv::Mat dst1; //가우시안 노이즈가 추가된 영상  
    cv::Mat dst2; //양방향 필터링 결과 영상
    cv::Mat dst3; //양방향 필터링 결과 영상
    cv::Mat dst4; //양방향 필터링 결과 영상
    
    cv::Mat noise(src.size(), CV_32SC1); //noise 행렬 생성
    cv::randn(noise, 0, 20); //가우시안 노이즈 생성. 평균 0, 표준편차 5


    cv::add(src, noise, dst1, cv::noArray(), CV_8UC1); //노이즈 추가. 결과는 dst1에 저장
    cv::imshow("Added Gaussian Noise", dst1);
    cv::waitKey(0); 

    cv::bilateralFilter(dst1, dst2, -1, 10, 5); //양방향 필터링 수행
    cv::bilateralFilter(dst2, dst3, -1, 5, 5); //양방향 필터링 수행
    cv::bilateralFilter(dst3, dst4, -1, 1, 5); //양방향 필터링 수행
    cv::imshow("Bilateral Filter Result 2", dst2);
    cv::imshow("Bilateral Filter Result 3", dst3);
    cv::imshow("Bilateral Filter Result 4", dst4);
    cv::waitKey(0); 
    cv::destroyAllWindows();

    return;
}


//양방향 필터
void show8()
{ 
    cv::Mat src{cv::imread("lenna.bmp", cv::IMREAD_GRAYSCALE)};
    cv::imshow("SRC", src);
   
    cv::Mat dst1; //가우시안 노이즈가 추가된 영상      
    cv::Mat dst2; //median 필터링 결과 영상
    
        
    // cv::Mat noise(src.size(), CV_32SC1); //noise 행렬 생성
    // cv::randn(noise, 0, 20); //가우시안 노이즈 생성. 평균 0, 표준편차 5
    // cv::add(src, noise, dst1, cv::noArray(), CV_8UC1); //노이즈 추가. 결과는 dst1에 저장

    int num=(int)(src.total()*0.1);
    for(int i=0;i<num;i++) {
        int x=rand() % src.cols;
        int y=rand() % src.rows;
        src.at<uchar>(y,x) = (i%2)*255;
    }
    
    cv::imshow("Salt & Pepper Noise", src);

    cv::GaussianBlur(src, dst1, cv::Size(), 1);
    cv::imshow("Added Gaussian Noise", dst1);


    cv::medianBlur(src, dst2, 3); //median 필터링 수행
    cv::imshow("Median Filter Result", dst2);
    cv::waitKey(0); 

    cv::destroyAllWindows();

    return;
}