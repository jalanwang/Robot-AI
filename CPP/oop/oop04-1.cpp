#include <iostream>
#include <memory>

class Shape {
public:
    virtual void draw() {
        std::cout << "도형을 그립니다." << std::endl;
    }
};
class Triangle : public Shape{
public:
    void draw() override{
        std::cout << "삼각형을 그립니다." << std::endl;
    }
};

class Rectangle : public Shape{
public:
    void draw() override{
        std::cout << "사각형을 그립니다." << std::endl;
    }
};

class Circle : public Shape{
public:
    void draw() override{
        std::cout << "동그라미를 그립니다." << std::endl;
    }
};

int main() 
{
    Shape* shape[4];
    shape[0] = new Shape();
    shape[1] = new Triangle();
    shape[2] = new Rectangle();
    shape[3] = new Circle();

    for(int i=0;i<4;i++) {
        shape[i]->draw();
        delete shape[i];
    }
}