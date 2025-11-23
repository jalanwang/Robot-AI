//이름을 입력받아 테두리로 묶인 인사말을 생성
#include <iostream>
#include <string>

int main()
{
    bool flag1;
    bool flag2;

    flag1=true;
    flag2=false;
    
    if(flag1) std::cout << "진실" << std::endl;
    else std::cout << "거짓" << std::endl;

    if(flag2) std::cout << "진실" << std::endl;
    else std::cout << "거짓" << std::endl;

    int a=100;
    double b=3.14;
    a=b;

   return 0;
}