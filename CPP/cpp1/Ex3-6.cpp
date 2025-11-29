#include <iostream>

class Rect {
public:
    int width;
    int height;

    Rect() : width(1), height(1) {}
    Rect(int _width, int _height) {
        width = _width;
        height = _height;
    }
    Rect(int _width) {
        width = _width;
        height = _width;
    }

    bool isSquare() {
        return width == height;
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

