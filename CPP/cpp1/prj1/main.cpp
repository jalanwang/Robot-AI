#include <iostream>
#include <cstring>

#include "circle.h"

int main() {
    
    using namespace std;

    Circle donut;
    double area=donut.getArea();
    cout << "도넛의 면적은: " << area << endl;

    Circle pizza(30);
    area=pizza.getArea();
    cout << "피자의 면적은: " << area << endl;

    return 0;
}