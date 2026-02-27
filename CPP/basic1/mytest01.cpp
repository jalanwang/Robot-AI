//자동차클래스를 만들고 사용해보자.

#include <iostream>
#include <string>

class Car
{
public:
    //1. 멤버변수
    int speed;
    std::string brand;
    std::string color;

    //2. 생성자
    Car(): speed(0), brand("기아"), color("검정") {}
    
    Car(int speed, std::string brand, std::string color) {
        this->speed = speed;
        this->brand = brand;
        this->color = color;        
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
    /* myCar.speed = 100;
    myCar.brand = "KIA";
    myCar.color = "검정색"; */

    std::cout << "myCar.speed: " << myCar.speed << std::endl;
    std::cout << "myCar.brand: " << myCar.brand << std::endl;
    std::cout << "myCar.color: " << myCar.color << std::endl;

    //멤버메소드 호출
    std::cout <<myCar.run() << std::endl;

    return 0;
}

