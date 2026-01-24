#include <iostream>
#include <memory>

class Shape {
public:
    virtual void draw() {
        std::cout << "도형을 그립니다." <<std::endl;
    }
};

class Triangle : public Shape {
public:
    void draw() override {
        std::cout << "삼각형을 그립니다." << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "사각도형을 그립니다." << std::endl;
    }
};

class Circle : public Shape {
public:
     void draw() override {
        std::cout << "원형을 그립니다." << std::endl;
    }
};

int main() 
{
    Shape* s1 = new Shape();
    Shape* s2 = new Triangle();
    Shape* s3 = new Rectangle();
    Shape* s4 = new Circle();

    s1->draw();
    s2->draw();
    s3->draw();
    s4->draw();
}

