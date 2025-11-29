//MMORPG 게임의 기사(Knight) 클래스를 정의하고, 객체(인스턴스)를 생성하여
//멤버변수와 멤버메소드를 사용하는 예제 코드입니다.

#include <iostream>
#include <string>

class Knight
{
public:
    //1. 멤버변수
    int level;
    std::string name;
    int hp;
    int mp;
    
    //2. 생성자
    Knight(): level(1), name("기사"), hp(100), mp(50) {}
    Knight(std::string name, int level=1, int hp=100, int mp=50) {
        this->level = 1;
        this->name = name;
        this->hp = 100;
        this->mp = 50;        
    }

    //3. 멤버메소드
    std::string attack() {
        return(name + "이(가) 손과 발로 공격!n");
    }
    std::string attack(std::string weapon) {
        return(name + "이(가) " + weapon + " 공격!");
    }
    std::string attack(std::string weapon, std::string aura) {
        return(name + "이(가) " + weapon + "에" + aura + "을(를) 감싼 후 공격!");
    }
    std::string eat() {
        return(name + "이(가) 먹는다.! \n");
    }
};

int main()
{
    //Knight 클래스 타입의 객체(인스턴스) 생성
    Knight k1("제임스", 1, 100, 100);
    std::cout << "이름: " << k1.name << std::endl;
    std::cout << "레벨: " << k1.level << std::endl;
    std::cout << "체력: " << k1.hp << std::endl;
    std::cout << "마력: " << k1.mp << std::endl << std::endl;
    std::cout << k1.attack() << std::endl;
    std::cout << k1.attack("용살검") << std::endl;  
    std::cout << k1.attack("용살검", " 마기") << std::endl;  
    return 0;
}

