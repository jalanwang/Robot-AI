//좌표라는 개념이 있다. 이를 객체, Class로 만들면 어떻케 만들까??
//hint point class 만들기

#include <iostream>

class Point {
    private:
    int x;
    int y;
    
    public:    
    Point(int _x, int _y) {
        x = _x;
        y = _y; 
    }
    void display() {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    using namespace std;

    Point p1(3, 4);
    p1.display();

    Point p2(10, 20);
    p2.display();

    return 0;
}