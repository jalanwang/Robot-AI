#include <opencv2/opencv.hpp>
#include <iostream>

// InputArray를 이용하여 다양한 입력 타입을 처리하는 함수

void printMat(cv::InputArray _mat) {
 cv::Mat mat = _mat.getMat();
 std::cout << mat << std::endl;
}

int main() { 

    uchar data1[]={1,2,3,4,5,6};
    cv::Mat mat1(2,3,CV_8U, data1);
    printMat(mat1);

    std::vector<float> vec1 = {1.2f, 3.4f, -2.1f };
    printMat(vec1);

    return 0;
}