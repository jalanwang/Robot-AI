#include <iostream>
#include <memory>

class Shape {
protected:
	virtual void draw() {}
public:
	friend void paint(Shape* p);
	// p->draw();
	// delete p;
// }
};

class Circle : public Shape {
	protected:
	void draw() override {
		std::cout << "원을 그리다." << std::endl;
	}
};


class Rect : public Shape {
	protected:
	void draw() override {
		std::cout << "사각형을 그리다." << std::endl;
	}
};



class Line : public Shape {
	protected:
	void draw() override {
		std::cout << "선을 그리다." << std::endl;
	}
};

void paint(Shape* p) { 
	p->draw();
	delete p;
}

int main() {

	paint(new Circle()); //Circle을 그린다.
	paint(new Rect()); //사각형을 그린다.
	paint(new Line()); //선을 그린다.

	return 0;

}