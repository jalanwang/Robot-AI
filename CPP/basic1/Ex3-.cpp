#include <iostream>
#include <cstring>

class Circle {

    public:
    int radius;
    std::string color;
    Circle() {
        radius=1;
        std::cout << "반지름: " << radius << std::endl;
    }
    Circle(int r) {
        radius=r;
        std::cout << "반지름: " << radius << std::endl; 
    }
    Circle(int r, std::string color)
    {
        radius=r;
        color="Red";        
        std::cout << "반지름: " << radius <<  "색" << color << std::endl; 
    }

};

int main() {
    using namespace std;

 //   Circle donut;
    Circle pizza(30);
    Circle tyre(10, "RED");
    
    return 0;
}