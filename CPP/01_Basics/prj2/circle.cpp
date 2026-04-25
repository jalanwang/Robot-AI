#include <iostream>
#include <cstring>

#include "circle.h"
//ifndef _CIRCLE_H_
//define _CIRCLE_H_

Circle::Circle() {
    radius=1;
    std::cout <<"반지름: " << radius ;
    std::cout << "원 생성" << std::endl;
}

Circle::Circle(int r) {
    radius=r;
    std::cout <<"반지름: " << radius ;
    std::cout << "원 생성" << std::endl;
}

double Circle::getArea() {
    return 3.14 * radius * radius;
}//endif