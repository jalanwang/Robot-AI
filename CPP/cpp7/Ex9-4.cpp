#include <iostream>
using namespace std;

class Shape {
public:
	virtual void draw() { 
		cout << "--Shape--";
	}
};

class Circle : public Shape {
public:
	void draw() override { 
		Shape::draw(); // 기본 클래스의 draw() 호출
		cout << "Circle" << endl;
	}
};

int main()
{
    Shape* s = new Circle();

    s->draw();
    s->Shape::draw();    

    delete s;
    return 0;
}