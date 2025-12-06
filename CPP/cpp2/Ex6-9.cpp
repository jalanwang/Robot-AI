#include <iostream>
#include <string>

// void msg(int id) {
// 	std::cout << id << std::endl;

// }

void msg(int id, std::string s=" ") {
	std::cout <<id << "." << s << std::endl;
}


int main() {
	
	msg(6);
	msg(5, "good morning");
	
	return 0;
}