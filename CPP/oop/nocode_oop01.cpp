#include <iostream>

class Cat {
    private: 
    int mAge;
    std::string mName;

    public:

    Cat()=default;
    Cat(int mAge, std::string mName): mAge(1), mName("Kitosan");
    ~Cat(){
        std::cout << "destructor" << std::cout;        

    }
    void speak() {}




};

int main() {
    Shape shape;
    shape.draw();

    Circle circle;
    circle.draw();

    Triangle triangle;
    triangle.draw();

}