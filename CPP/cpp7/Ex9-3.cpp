#include <iostream>

class Base {
public: 
	virtual void f() {std::cout << "Base::f() called" << std::endl; }
};

class Derived : public Base {
public: 
	void f() { std::cout << "Derived::f() called" << std::endl; }
};

class GrandDerived  : public Derived {
public: 
	void f() { std::cout << "GrandDerived::f() called" << std::endl; }
};

int main() {
	
    GrandDerived g; //객체생성

	Base bp; 
	Derived dp;
	GrandDerived gp;

	bp = dp = gp = g;

	bp.f();
	dp.f();
	gp.f();
}
