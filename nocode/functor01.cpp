// operator() 오버로딩을 이용한 함수 객체(Functor) 예제
// 함수 객체는 상태를 가질 수 있습니다.

#include <iostream>

class Accumulator {
private:
    int m_total = 0; // 누적 값을 저장할 상태 변수

public:
    // operator()를 오버로딩하면 객체를 함수처럼 호출할 수 있습니다.
    int operator()(int val) {
        m_total += val; // 멤버 변수(상태)를 변경 및 유지
        return m_total;
    }
};

int main() {
    Accumulator acc; // Accumulator 객체 생성

    // 객체 acc를 마치 함수처럼 사용합니다.
    std::cout << "10 더하기: " << acc(10) << std::endl; // 10 출력
    std::cout << "20 더하기: " << acc(20) << std::endl; // 10 + 20 = 30 출력
    std::cout << "5 더하기: " << acc(5) << std::endl;   // 30 + 5 = 35 출력

    return 0;
}