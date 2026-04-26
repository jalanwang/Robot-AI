#include <iostream>

class Circle {
    private:
        int radius;
    public:
        Circle(int r) : radius(r) {}
        int getArea() {
                return 3.14*radius*radius;        
        }
        // Circle(const Circle& other) {
        //     std::cout <<"복사 생성자 실행!!" << std::endl;
        //     this->radius = other.radius;
        // }       

};

int main()
{

    Circle src(30);
    Circle dst(src); //매개변수가 객체인 생성자로 값을 복사 생성!

    std::cout << "사본의 면적: " << dst.getArea() << std::endl;
    return 0;
}

