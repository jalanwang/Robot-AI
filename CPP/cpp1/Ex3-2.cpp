//switch문
#include <iostream>
#include <string>

int score;

int main()
{
    int score, div;
    std::cout << "점수를 입력하세요" << std::endl;
    std::cin>>score;
    div=score/10;

    switch(div) {
        case 10:            
        case 9: 
            std::cout<<"A"<<std::endl;
            break;
        case 8: 
            std::cout<<"B"<<std::endl;
            break;
        case 7: 
            std::cout<<"C"<<std::endl;
            break;
        case 6: 
            std::cout<<"D"<<std::endl;
            break;
        default:
            std::cout<<"F"<<std::endl;
            break;
    }
    return 0;
}