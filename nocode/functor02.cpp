#include <iostream>

struct MyNumber {
    int value; // struct는 기본 접근 지정자가 public이므로 별도 선언이 필요 없습니다.

    // 1. '+' 연산자 오버로딩
    // 객체 + 정수 형태를 가능하게 함
    int operator+(int x) const {
        return value + x;
    }

    // 2. '()' 연산자 오버로딩 (이게 바로 펑터)
    // 객체(정수) 형태를 가능하게 함
    int operator()(int x) const {
        return value * x; // 예: 괄호 안의 값과 곱하기
    }
};

int main() {
    MyNumber n;
    n.value = 10;

    // operator+ 호출
    int sum = n + 5;   // 내부적으로 n.operator+(5) 호출
    std::cout << "덧셈 결과: " << sum << std::endl; // 15

    // operator() 호출
    int mul = n(5);    // 내부적으로 n.operator()(5) 호출
    std::cout << "곱셈(펑터) 결과: " << mul << std::endl; // 50

    return 0;
}