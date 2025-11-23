#include <iostream>

class Car {
public:
    int speed;
    std::string brand;
    
    virtual void run() {
        std::cout << "차가 달리다!" << std::endl;     
        
    }
};

class SuperCar : public Car {
    public:
    
    int booster;

    SuperCar() {
        booster=100;
    }  

    void run() override {
        std::cout << booster <<"부스터 용량으로 차가 달리다!" << std::endl;
    }
};

int main() {
    Car car1;
    SuperCar car2;
    car1.run();
    car2.run();

    return 0;
}