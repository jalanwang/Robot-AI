#include <iostream>

class Circle {
    private:
    int radius;
    public:
    Circle() : radius(1) {
        this->radius =1;
    }
    //Circle(int radius) : radius(radius) {}
    Circle(int radius)  {
        this->radius = radius;
    }
    //

    ~Circle() {}

    void setRadius(int radius) {
        this->radius = radius;
    }

    int getRadius() {
        return radius;
    }
};
    
int main() {
    Circle c1;
    c1.setRadius(5);
    std::cout << "반지름: " << c1.getRadius() << std::endl; 


    return 0;
}
