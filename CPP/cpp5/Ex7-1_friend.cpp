#include <iostream>

class Rect; //전방선언이 중요하다.

class RectManager { // RectManager 클래스 선언
public:
	bool equals(Rect r, Rect s);
};

class Rect { // Rect 클래스 선언
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend bool RectManager::equals(Rect r, Rect s); 
};

bool RectManager::equals(Rect r, Rect s) { 
	if(r.width == s.width && r.height == s.height) return true; 
	else return false;
}

int main() {
	Rect a(3,4), b(3,4);
	RectManager man;
	
	if(man.equals(a, b)) std::cout << "equal" << std::endl;
	else std::cout << "not equal" << std::endl; 
}
