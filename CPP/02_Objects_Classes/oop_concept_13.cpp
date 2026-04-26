#include <iostream>
#include <memory>

class Person {
};

class Student : public Person {
};

int main() {
    Person gildong_father; //stack -delete(x)
    std::unique_ptr<Person> gildong = std::make_unique<Person>(); //heap 영역에 Person 객체 생성
    Person* gildong2 = new Student(); //heap 영역에 Student 객체 생성
    delete gildong2; //명시적으로 delete 해줘야함
       

    return 0;
}
