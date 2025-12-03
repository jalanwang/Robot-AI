/*
추상클래스 구현 연습
*/

#include <iostream>

class Calculator {
public:
    virtual int add(int a, int b)=0;
    virtual int subtract(int a, int b)=0;
	virtual double average(int a [], int size)=0;	
};

class GoodCalc : public Calculator {

public:
	int add(int a, int b) { return a + b; }	
	int subtract(int a, int b) { return a - b; }	
	double average(int a [], int size) {
		double sum = 0;
		for(int i=0; i<size; i++) 
			sum += a[i];
		return sum/size;
	}	
};

int main() {
	int a[] = {1,2,3,4,5};
	Calculator *p = new GoodCalc();
	std::cout << p->add(2, 3) << std::endl;
	std::cout << p->subtract(2, 3) << std::endl;
	std::cout << p->average(a, 5) << std::endl;
	delete p;
}