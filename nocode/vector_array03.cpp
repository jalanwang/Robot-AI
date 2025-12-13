// for 반복문과 벡터
// class를 담고 있는 벡터

#include <iostream> 
#include <vector>

class Cat {
private:
    int mAge;
public:
    explicit Cat (int age): mAge{age} {} //매개변수가 1개면 explicit 넣어 주자.
    void speak() const{
        std::cout << "meow~ by " << mAge;
    }

};

int main() {
    std::vector<Cat> cats;
    
    cats.emplace_back(Cat(1));
    cats.emplace_back(Cat(2));
    cats.emplace_back(Cat(3));
    cats.emplace_back(Cat(4));

    cats[0].speak();
    std::cout << std::endl;

    // for(auto itr : cats) {
    //     itr.speak();
    //     std::cout << std::endl;
    // }

    for(const auto& itr : cats) { //이걸 추천
        itr.speak();
        std::cout << std::endl;
    }

    return 0;
}