#include <iostream> 

class Circle {
public:
	int mRadius; 
	Circle(); 
	Circle(int r); 
	~Circle(); 
	double getArea(); 
}; 

Circle::Circle() {
	mRadius = 1;
	std::cout << "반지름 " << mRadius << " 원 생성" << std::endl;
}

Circle::Circle(int r) {
	mRadius = r;
	std::cout << "반지름 " << mRadius << " 원 생성" << std::endl;
}

Circle::~Circle() {
	std::cout << "반지름 " << mRadius << " 원 소멸" << std::endl;
}

double Circle::getArea() {
	return 3.14*mRadius*mRadius;
}

Circle globalDonut(1000);
Circle globalPizza(2000);

void foo() {
	Circle fooDonut(100);
	Circle fooPizza(200);
}

int main() {
	Circle mainDonut;
	Circle mainPizza(30);
	foo();

    return 0;
}   