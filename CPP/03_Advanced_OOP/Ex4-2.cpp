#include <iostream>
#include <string>

//string class 연습

int main() {
std::string str("I love ");
std::string str2="123";

str.append(str2);
std::string str3(str2);
std::cout << str << std::endl;
std::cout << std::stoi(str2)+ 10 << std::endl;

    return 0;
}
