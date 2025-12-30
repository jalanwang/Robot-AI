#include <iostream>
#include <typeinfo>

// 클래스 템플릿 정의
template <typename T>
class Calculator {
private:
    T val1;
    T val2;

public:
    // 생성자: 멤버 변수 초기화
    Calculator(T v1, T v2) : val1(v1), val2(v2) {}

    // 덧셈 수행 함수
    T add() {
        return val1 + val2;
    }

    // 현재 T의 타입을 확인하기 위한 헬퍼 함수
    const std::string getTypeName() {
        return typeid(T).name();
    }
};

int main() {
    std::cout << std::showpoint; // 실수 소수점 표시 설정

    // 1. int 타입 인스턴스화
    Calculator<int> intCalc(10, 20);
    std::cout << "Int Add: " << intCalc.add() << std::endl;

    // 2. float 타입 인스턴스화
    Calculator<float> floatCalc(10.0f, 20.0f);
    std::cout << "Float Add: " << floatCalc.add() << std::endl;

    // 3. double 타입 인스턴스화 (C++17부터는 <double> 생략 가능 - CTAD)
    Calculator<double> doubleCalc(10.0, 20.0);
    std::cout << "Double Add: " << doubleCalc.add() << std::endl;

    std::cout << "\n--- Type Check ---" << std::endl;
    // 클래스 내부에서 T가 무엇으로 결정되었는지 확인
    std::cout << "FloatCalc T is:  " << floatCalc.getTypeName() << std::endl;
    std::cout << "DoubleCalc T is: " << doubleCalc.getTypeName() << std::endl;

    return 0;
}