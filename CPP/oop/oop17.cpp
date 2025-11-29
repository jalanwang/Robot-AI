// 자식 클래스에서 부모 클래스의 매개변수가 있는 생성자를 기본으로 호출하는 방법 설명
#include <iostream>
#include <memory>
#include <cstdlib>

class A {
    public:
    // A() {
    //     std::cout << "A 생성자 호출" << std::endl;
    //  }
    A(int x)
     {
        std::cout << "매개변수가 있는 생성자 A 호출: " << x << std::endl;
    }
};


class B: public A {
    public:
    // B() {
    //     std::cout << "B 생성자 호출" << std::endl;
    //  }
    B(int x): A(x)
     {
        std::cout << "매개변수가 있는 생성자 B 호출: " << x << std::endl;
    }
};

int main() {
    B b(5);
}