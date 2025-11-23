#include <iostream>

class Cat {
public:
   Cat() {
    std::cout << "고양이 생성자 호출!" << std::endl;
   }

   ~Cat() {
    std::cout << "고양이 소멸자 호출!" << std::endl;
   }  

};
int main() {
    Cat tom;
    Cat jack;
    
    return 0;
}

