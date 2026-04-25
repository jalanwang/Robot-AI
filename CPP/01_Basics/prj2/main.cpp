#include <iostream>

class Circle { 
    private:
    int radius;
    Circle():radius(1) {
        //radius=1;
        std::cout <<"반지름: " << radius ;        
    }
    Circle(int r):radius(r) {
        std::cout <<"반지름: " << radius ;
    }
};

int main() {
    
    using namespace std;

    Circle donut;    
    Circle pizza(30);
    

    return 0;
}