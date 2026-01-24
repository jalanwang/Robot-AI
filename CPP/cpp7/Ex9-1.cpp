#include <iostream>
#include <memory>

using namespace std;


class Parent {
public:
	virtual void f() { cout << "Parent::f() called" << endl; }
};

class Child : public Parent {
public:
	void f() override { cout << "Child::f() called" << endl; }
};

int main() {
	unique_ptr<Child> child = make_unique<Child>();
    child->f();

    // Derived d;
    // Derived* pDer;
	// pDer = &d; //객체의 시작주소를 pDer에 대입
	// pDer->f(); // Derived::f() 호출 //
 
    unique_ptr<Parent> parent = make_unique<Child>();
    parent->f();

	// Base* pBase;
	// pBase = pDer; // 업캐스팅
	// pBase->f(); // Base::f() 호출

    return 0;
}

/*
기사, 검사, 마법사를 사용한다.

*/