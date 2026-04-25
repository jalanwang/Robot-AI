/*
 * 미션: 자동차 캡슐화 구현하기 (Ex3-8)
 * 
 * 1. Car 클래스를 정의하세요.
 * 2. private 멤버 변수: int speed
 * 3. 생성자: 초기화 리스트를 사용하여 speed를 0으로 초기화
 * 4. public 멤버 함수:
 *    - void setSpeed(int _speed): 속도 설정
 *    - int getSpeed(): 현재 속도 반환
 * 5. main 함수:
 *    - Car 객체 생성
 *    - 속도를 100으로 설정
 *    - "현재 속도: 100km/h"와 같이 출력
 */

#include <iostream>

class Car {
    private:
        int m_speed;
    public:
        Car() : m_speed(0) {}
        void setSpeed(int speed) {
            m_speed = speed;
        }
        int getSpeed() {
            return m_speed;
        }
};

int main () {
    Car myCar;
    
    myCar.setSpeed(100);
    std::cout << "현재 속도: " << myCar.getSpeed() << "km/h" << std::endl;

    return 0;
}