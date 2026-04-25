#include <iostream>
#include <memory>

class Shape {
public:
    virtual void draw() {
        std::cout << "도형을 그리다" <<std::endl;

    }
};
class Triangle : public Shape {
    public: 
    void draw() override {
    std::cout << "삼각형을 그리다" <<std::endl;

    }
};

class Rectangle : public Shape {
    public:
    void draw() override {
    std::cout << "사각형을 그리다" <<std::endl;
    }
};

class Circle : public Shape {
    public:
    void draw() override {
    std::cout << "원을 도형을 그리다" <<std::endl;
    }
};

int main() { //부모클래스포인터로 자식 클래스 객체를 생성할 수 있다.
    
    Shape* s1 = new Shape();
    Shape* s2 = new Triangle();
    Shape* s3 = new Rectangle();
    Shape* s4 = new Circle();

    s1->draw();
    s2->draw();
    s3->draw();
    s4->draw();

    delete s1, s2, s3, s4;

    return 0;
}