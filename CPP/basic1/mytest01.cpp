//자동차클래스를 만들고 사용해보자.

#include <iostream>
#include <string>

class Car
{
private:
    //1. 멤버변수
    int m_speed;
    std::string m_brand;
    std::string m_color;
public:

    //2. 생성자
    Car(): m_speed(0), m_brand("기아"), m_color("검정") {}
    
//    Car(int speed, std::string brand, std::string color) {
//        m_speed = speed;
//        m_brand = brand;
//        m_color = color;        
//    }   

    Car(int speed, std::string brand, std::string color): m_speed(speed), m_brand(brand), m_color(color) {}    

    //getter 추가
    int getSpeed() {
        return m_speed;
    }
    std::string getBrand() {
        return m_brand;
    }
    std::string getColor() {
        return m_color;
    }
   
    //3. 멤버메소드
    std::string run() {
        return("달리다~~!!!\n");
    }
};

int main()
{
    //Car 클래스 타입의 객체(인스턴스) 생성
    Car myCar(100, "KIA", "검정색");

    //멤버변수 접근

    std::cout << "myCar.speed: " << myCar.getSpeed() << std::endl;
    std::cout << "myCar.brand: " << myCar.getBrand() << std::endl;
    std::cout << "myCar.color: " << myCar.getColor() << std::endl;

    //멤버메소드 호출
    std::cout <<myCar.run() << std::endl;

    return 0;
}

