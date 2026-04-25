#include <iostream>

class Shape {
public:
    int lineThick;
    virtual void draw() {
        std::cout << "도형을 그립니다." << std::endl;
    }
    Shape():lineThick(1) {}
};

class Circle: public Shape{
public:
    void draw() override {
    std::cout << "원을 그립니다." << std::endl;
    }
};

class Triangle: public Shape{
public:
    void draw() override {
    std::cout << "삼각형을 그립니다." << std::endl;
    }

};

int main() {
    Shape shape;
    shape.draw();

    Circle circle;
    circle.draw();

    Triangle triangle;
    triangle.draw();

}