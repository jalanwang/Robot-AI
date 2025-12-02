#include <iostream>


class Person {
public:
	int money=0; // 개인 소유의 돈
	static int sharedMoney; // 공금
	
	Person() {
		money++;
		sharedMoney++;
	}
};

int Person::sharedMoney=10000;

int main()
{
	Person p1;
	std::cout << p1.money << std::endl;	
	Person p2;
	std::cout << p2.sharedMoney << std::endl;
	Person p3;
	std::cout << p3.sharedMoney << std::endl;
}