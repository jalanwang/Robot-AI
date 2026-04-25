/*

%%%%%%%%%%
@@@@@@@@@@
@@@@@@@@@@
@@@@@@@@@@
@@@@@@@@@@
@@@@@@@@@@
*/

#include <iostream>
#include <memory>

void myPrint(char c=' ', int cnt = 1) {
	for(int i=0;i<cnt;i++) { //입력된 횟수만큼 반복
		for(int j=0;j<10;j++) { //10번 반복
			std::cout << c;
		}
		std::cout << std::endl;
	}
}

int main() {
	myPrint();
	myPrint('%');
	myPrint('@', 5);

	return 0;
}