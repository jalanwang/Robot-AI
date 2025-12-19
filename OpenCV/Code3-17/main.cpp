#include <opencv2/opencv.hpp>
#include <iostream>

void printMat(cv::InputArray _mat) {
 cv::Mat mat = _mat.getMat();
 std::cout << mat << std::endl;
}

int main() { // 다형성에 대한 내용도 담고 있다고 하는데 모르겠다.    

    uchar data1[]={1,2,3,4,5,6};
    cv::Mat mat1(2,3,CV_8U, data1);
    printMat(mat1);

    std::vector<float> vec1 = {1.2f, 3.4f, -2.1f };
    printMat(vec1);

    return 0;
}