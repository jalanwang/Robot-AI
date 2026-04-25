#include <iostream>

class Person {
public:
	int money; // 개인 소유의 돈
	void addMoney(int money) {
		this->money += money;
	}

	static int sharedMoney; // 공금
	static void addShared(int n) {
		sharedMoney += n;
	}
};

// static 변수 생성. 전역 공간에 생성
int Person::sharedMoney=0;  // 10으로 초기화 //14버젼 //17버젼에서는 inline 키워드를 이용해서 클래스 내부에서 선언 가능

// main() 함수
int main() {
	Person han;
	han.money = 100; // han의 개인 돈=100	
	han.sharedMoney = 200; // static 멤버 접근, 공금=200

	Person lee;
	lee.money = 150; // lee의 개인 돈=150
	lee.addMoney(200); // lee의 개인 돈=350
	lee.addShared(200); // static 멤버 접근, 공금=400
	std::cout << "han.money     lee.money " << std::endl;
	std::cout << han.money << "           " << lee.money << std::endl;
	std::cout << "han.shared    lee.shared " << std::endl;
	std::cout << han.sharedMoney << "           " << lee.sharedMoney << std::endl;
}
