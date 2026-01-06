//std::set

#include <iostream> 
#include <set>

class Cat {
private: 
    int mAge;
    std::string mName;
public:
    Cat(int age, std::string name) : mAge(age), mName(std::move(name)) {}

    void speak() const {
        std::cout << "Meow! My name is " << mName << " and I am " << mAge << " years old." << std::endl;
    }
    int getAge() const {
        return mAge;
    }
    const std::string& getName() const {
        return mName;
    }
// 차이점 설명
// std::string getName() const (값 반환)
// mName의 복사본을 생성하여 반환합니다.
// 문자열이 길 경우 메모리 할당과 데이터 복사가 발생하여 성능 오버헤드가 있습니다.
// const std::string& getName() const (const 참조 반환)
// mName 원본에 대한 읽기 전용 별명(참조)만 반환합니다.
// 복사가 발생하지 않아 매우 빠르고 효율적입니다.
};

int main() {
    // std::set의 두 번째 템플릿 인자로 우리가 만든 비교 구조체를 전달합니다.
    std::set<Cat> cats;

    cats.emplace(Cat(1, "cat1"));
    cats.emplace(Cat(2, "cat2"));
    
    for(const Cat& cat: cats) {
        cat.speak();
    }
    return 0;
}