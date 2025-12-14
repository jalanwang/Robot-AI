// for 반복문과 벡터
// emplace_back 사용 시, 오브젝트 생성 시간을 줄이기 위한 방법

#include <iostream> 
#include <vector>

class Cat {
private:
    std::string mName;
    int mAge;
public:
    Cat (std::string name, int age): mName{std::move(name)}, mAge{age} {}
    void speak() const{
        std::cout << "meow~ " << mName << mAge << std::endl;
    }
};

int main() {
    std::vector<Cat> cats;

    cats.emplace_back("cat0", 0);
    cats.emplace_back("cat1", 1);

    Cat& cat = cats.emplace_back("kitty", 2);

    Cat nabi{"nabi",3};
    cats.emplace_back(std::move(nabi));

    for(const auto& cat : cats) {
        cat.speak();
    }
    return 0;
}