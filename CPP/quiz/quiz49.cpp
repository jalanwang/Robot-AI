/*
Q49) 다음 Car 클래스를 inner class 형태의 빌더패턴으로 수정해 보아라.
inner class형태의 빌더패턴 또는 블로치(Bloch)빌더로 불리는 가장 간단한 형태의
매개변수 개수를 줄여서 생성할 수 있는 패턴을 사용해 봅시다.
*/

#include <iostream>
#include <memory>

class Car {

private:
    std::string mBrand;
    int mSpeed;
    std::string mColor;

    // 생성자를 private로
    Car(const std::string& brand, int speed, const std::string& color)
        : mBrand(brand), mSpeed(speed), mColor(color) {}

public:
    //빌더패턴 사용 클래스 시작
    class Builder { 
    private:
        std::string mBrand="Genesis";
        int mSpeed=300;
        std::string mColor="White";    

    public:
        Builder& setBrand(const std::string& brand) {
        mBrand=brand;
        return *this;
    }
    Builder& setSpeed(const int speed) {
        mSpeed=speed;
        return *this;
    }
    Builder& setColor(const std::string& color) {
        mColor=color;
        return *this;
    }
    
    Car build() const {
        return Car(
            mBrand, mSpeed, mColor
        );
    }
    }; //Builder Class 종료

    //getter
    std::string getBrand() { 
        return mBrand; 
    }
    int getSpeed() { 
        return mSpeed; 
    }
    std::string getColor() { 
        return mColor; 
    }
}; //Car Class 종료

int main() {

 Car genesis = Car::Builder()
                        .setBrand("제너시스")
                        .setSpeed(300)
                        .setColor("Pearl White")                        
                        .build();   

    std::cout << "==== Car Info ====\n";
    std::cout << "Brand: " << genesis.getBrand() << std::endl;
    std::cout << "Speed: " << genesis.getSpeed() << std::endl;
    std::cout << "Color: " << genesis.getColor() << std::endl;
    
    return 0;

}