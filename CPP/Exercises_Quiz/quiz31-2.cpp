//좌표라는 개념이 있다. 이를 객체, Class로 만들면 어떻케 만들까??
//위임생성자, 타겟생성자 개념잡기

#include <iostream>

class Point {
    private:    
       int x,y;

    public:
        Point();
        Point(int _x, int _y);

        void display() {
            std::cout << "Point(" << x << ", " << y << ")" << std::endl;
        }
};
//Point::Point() {
//    x=0;
//    y=0;  
//}
Point::Point():Point(0,0) {} //위임생성자

//Point::Point(int a, int b) {
//    x=a;
//    y=b;   
//}
Point::Point(int _x, int _y):x(_x), y(_y) {} //타겟생성자

int main() {
    using namespace std;
    Point orgin; //기본생성자, 초깃값 0,0을 넣어서 타겟에 넣어 주었다.
    orgin.display();
    Point target(10,20);
    target.display();
   
    return 0;
}