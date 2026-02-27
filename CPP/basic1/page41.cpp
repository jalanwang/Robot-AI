//이름을 입력받아 테두리로 묶인 인사말을 생성
#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;
    
    //출력하려는 메시지를 구성
    std::string const greeting = "Hello, " + name + "!";
    
    //인사말의 두 번째 행과 네 번째 행
    std::string const spaces(greeting.size(), ' ');
    std::string const second = ("* " + spaces + " *");

    //인사말의 첫 번째 향과 다섯 번째 행

    std::string const first(second.size(), '*');

    //모두 출력
    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first <<std::endl;
    

   return 0;
}