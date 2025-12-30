#include <iostream>
#include <string>

// template <typename T> : T라는 이름으로 자료형을 나중에 받겠다고 선언
template <typename T>
class SimpleData {
private:
    T data; // T 타입의 멤버 변수 (int가 될 수도, string이 될 수도 있음)

public:
    // 생성자: T 타입의 값을 받아 초기화
    SimpleData(T d) : data(d) {}

    // 데이터 출력 함수
    void print() const {
        std::cout << "Stored Data: " << data << std::endl;
    }

    // 데이터 반환 함수
    T get() const {
        return data;
    }
};

int main() {
    // 1. int형으로 사용 (T가 int로 바뀜)
    SimpleData<int> intObj(100);
    intObj.print();

    // 2. double형으로 사용 (T가 double로 바뀜)
    SimpleData<double> doubleObj(3.14159);
    doubleObj.print();

    // 3. string형으로 사용 (T가 std::string으로 바뀜)
    SimpleData<std::string> strObj("Hello Template");
    strObj.print();

    return 0;
}