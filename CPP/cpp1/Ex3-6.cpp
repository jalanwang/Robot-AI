// Ex3-6.cpp
// 직사각형(Rect) 클래스 정의 및 사용 예제

#include <iostream>

class Rect {
public:
    int mWidth;
    int mHeight;

    Rect() :  mWidth(1), mHeight(1) {} // 기본 생성자  
    Rect(int width, int height) { // 매개변수 있는 생성자
        mWidth = width;
        mHeight = height;
    }
    Rect(int width) { // 정사각형 생성자
        mWidth = width;
        mHeight = width;
    }

    bool isSquare() {
        return mWidth == mHeight;
    }
};

int main() {
    Rect rect1;
    Rect rect2(3, 5);
    Rect rect3(3);

    if (rect1.isSquare())
        std::cout << "rect1은 정사각형이다." << std::endl;
    if (rect2.isSquare())
        std::cout << "rect2는 정사각형이다." << std::endl;
    else
        std::cout << "rect2는 직사각형이다." << std::endl;
    if (rect3.isSquare())
        std::cout << "rect3는 정사각형이다." << std::endl;

    return 0;
}

