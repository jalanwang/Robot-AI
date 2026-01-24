#include <iostream>

class Parent {
public:
    Parent() {
        std::cout <<"부모 생성자 호출" << std::endl;
    }
	virtual ~Parent() {
        std::cout <<"부모 소멸자 호출" << std::endl;
    }
};

class Child: public Parent {
public:
    Child() {
        std::cout <<"자식 생성자 호출" << std::endl;	
    }
	virtual ~Child() override {
        std::cout <<"자식 소멸자 호출" << std::endl;	
    }
};


int main() {

    Parent* p3 = new Child();
    delete p3;
// 	Parent p;
// 	Child c;
// `   std::cout << " -----------------------" << std::endl;
//     Parent *p2 = new Child();
// 	delete p2;

}
