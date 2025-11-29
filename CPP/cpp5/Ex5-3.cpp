#include <iostream>

class Circle
{
	public:
	void getArea() {
		std::cout << "넓이 구하기" << std::endl;
	}
};

int main()
{
	Circle circle; //객체 스택에 생성
	Circle& ref=circle; //ref레퍼런스, *ref->객체

	ref.getArea(); //레퍼런스를 통해 멤버 함수 호출
	
	return 0;
}
