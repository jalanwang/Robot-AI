#include <iostream>
#include <memory>

class Circle {
public:
    int radius;
    double getArea() {
        return 3.14*radius*radius;
    } 
};

int main() 
{
    Circle donut;
    std::cout << "도넛 면적: "<< donut.getArea() << std::endl;

    Circle* p = &donut;
    std::cout << "p의 면적2: " << p->getArea() << std::endl;
    std::cout << "p의 면적2: " << (*p).getArea() << std::endl;

    Circle* donut2 = new Circle();
    std::cout << "donut2의 면적3: " << donut2->getArea() << std::endl;
    std::cout << "donut2의 면적3: " << (*donut2).getArea() << std::endl;

    //delete *p <<<---- 바보같은 생각였다.
    delete donut2;
  

}
