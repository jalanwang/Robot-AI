#include <iostream>
#include <string>

class Rect {
    public:
        int width;
        int height;
        
        int area(int _width, int _height) { 
            return _width * _height;
        }
};

int main() {
    Rect r1;
    int a;
    int b;

    std::cout << "가로 세로 입력: ";
    std::cin >> a >> b;
    std::cout << r1.area(a,b) << std::endl;


    return 0;
}

