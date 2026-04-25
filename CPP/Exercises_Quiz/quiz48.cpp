/*
Q48) 다음 Student 클래스를 inner class 형태의 빌더패턴으로 수정해 보아라.
최고관리자  0건  5회 25-12-02 09:06
inner class형태의 빌더패턴 또는 블로치(Bloch)빌더로 불리는 가장 간단한 형태의

매개변수 개수를 줄여서 생성할 수 있는 패턴을 사용해 봅시다.
*/

#include <iostream>
#include <memory>

class Student {

private:
    std::string mName;
    int mAge;
    std::string mMajor;
    int mId;


    // 생성자를 private로
    Student(const std::string& name, int age, const std::string& major, int id)
        : mName(name), mAge(age), mMajor(major), mId(id) {}


    public:
    // std::string getName() {
    //     return mName;
    // }

    class Builder { 
    private:
    std::string mName="이름";
    int mAge=1;
    std::string mMajor="컴퓨터공학";
    int mId=0;

    public:
    Builder& setName(const std::string& name) {
        mName=name;
        return *this;
    }
    Builder& setAge(const int age) {
        mAge=age;
        return *this;
    }
    Builder& setMajor(const std::string& major) {
        mName=major;
        return *this;
    }
    Builder& setId(const int id) {
        mId=id;
        return *this;
    }   
    Student build() const {
        return Student(
            mName, mAge, mMajor, mId
        );
    }
    };
        //getter
    std::string getName() { 
        return mName; 
    }
    int getAge() { 
        return mAge; 
    }
    std::string getMajor() { 
        return mMajor; 
    }
    int getId() { 
        return mId;
    }

};

int main() {

 Student student = Student::Builder()
                        .setName("홍길동")
                        .setAge(20)
                        .setMajor("Embedded System")
                        .setId(20251234)
                        .build();   

    std::cout << "Student Info\n";
    std::cout << "Name:  " << student.getName() << std::endl;
    std::cout << "Age:   " << student.getAge() << std::endl;
    std::cout << "Major: " << student.getMajor() << std::endl;
    std::cout << "ID:    " << student.getId() << std::endl;

    return 0;

}