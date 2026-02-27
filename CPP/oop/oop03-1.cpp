#include <iostream>
#include <memory>

class Shape {
    public:
    virtual void draw() {
        std::cout << "도형을 그리다" <<std:: endl;
    }
};

class Rectangle : public Shape{
    public:
    void draw() override {
        std::cout << "사각형을 그리다" << std::endl;
    }
};

class Triangle : public Shape{
    public:
    void draw() override {
        std::cout << "삼각형을 그리다" << std::endl;
    }
};

class Circle : public Shape{
    public:
    void draw() override {
        std::cout << "원을 그리다." << std::endl;
    }
};

int main() {

    // Shape s1 = Shape();
    // Shape s2 = Rectangle();
    // Shape s3 = Triangle();
    // Shape s4 = Circle();    

    // s1. draw();
    // s2. draw();
    // s3. draw();
    // s4. draw();


    Shape* s1 = new Shape();
    Shape* s2 = new Rectangle();
    Shape* s3 = new Triangle();
    Shape* s4 = new Circle();

    s1->draw();
    s2->draw();
    s3->draw();
    s4->draw();

    delete s1;
    delete s2;
    delete s3;
    delete s4;

    return 0;
}

