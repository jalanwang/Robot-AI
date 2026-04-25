#include <iostream>

char& find(char s[], int idx) {
	return s[idx];
}

int main() {
	char name[] = "Mike";
	std::cout << name << std::endl;

	find(name,0) ='S';

	std::cout << name << std::endl;

	char& ref =find(name,2);
	ref='z';
	std::cout << name << std::endl;
	

	return 0;


}

// #include <iostream>

// char& find(char s[], int index) {
// 	return s[index]; //레퍼런스를 반환
// }

// int main()
// {	

// 	char name[]="Mike";
// 	std::cout << name << std::endl;

// 	find(name, 0)='S'; //레퍼런스를 통해 문자 변경
// 	std::cout << name << std::endl;

// 	char& ref=find(name, 2);
// 	ref='t'; //레퍼런스를 통해 문자 변경
// 	std::cout << name << std::endl;


// 	return 0;
// }
