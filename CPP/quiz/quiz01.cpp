#include <iostream>
#include <memory>

//문제 스마트 포인터 기법을 사용해서 heap 메모리에 leesunsin을 생성하세요.
class Person {
};

class Professor : public Person {
    public:
    Professor() {
        std::cout << "교수가 태어났습니다" << std::endl;
    }
    ~Professor() {
        std::cout << "교수가 사라졌습니다" << std::endl;
    }
};

int main() {

    std::unique_ptr<Professor> leesunsin = std::make_unique<Professor>();
    while(1) {}
    return 0;
}
