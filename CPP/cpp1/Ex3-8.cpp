#include <iostream>

class Car {
private:
    int speed;

public:
    Car() : speed(0) {}
    void setSpeed(int _speed) {
        this->speed = _speed;
    }
    int getSpeed() {
        return this->speed;
    }
};

int main() {
    Car myCar;
    myCar.setSpeed(100);
    std::cout << "현재 속도: " << myCar.getSpeed() << "km/h" << std::endl; 

    return 0;
}