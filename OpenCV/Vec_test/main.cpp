#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // 1. Vec3b 객체 생성 (B=255, G=0, R=0 - 파란색)
    // t=1이므로 인덱스 하나로 각 채널에 접근
    Vec3b blue(255, 0, 0); 
    
    // 2. 인덱스(축) 하나를 사용하여 데이터 접근
    cout << "Blue channel: " << (int)blue[0] << endl; // Index 0
    cout << "Green channel: " << (int)blue[1] << endl; // Index 1
    
    // 3. 연산 (Scalar와 Vector의 곱)
    // 모든 성분에 0.5를 곱해 밝기를 낮춤
    Vec3b half_blue = blue * 0.5; 
    
    // 4. 행렬(Matrix, t=2)의 특정 위치에 벡터(Vector, t=1) 대입
    Mat img(100, 100, CV_8UC3, Scalar(255, 255, 255)); // 흰색 배경 이미지
    
    // (50, 50) 위치에 blue 벡터 대입
    img.at<Vec3b>(50, 50) = blue; 

    cout << "Result Vector: " << half_blue << endl;

    return 0;
}