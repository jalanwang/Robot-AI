//MMORPG 게임의 기사(Knight) 클래스를 정의하고, 객체(인스턴스)를 생성하여
//멤버변수와 멤버메소드를 사용하는 예제 코드입니다.

#include <iostream>
#include <string>

class Knight
{
private:
    //1. 멤버변수
    int m_level;
    std::string m_name;
    int m_hp;
    int m_mp;
    
public:
    //2. 생성자
    Knight(): m_level(1), m_name("기사"), m_hp(100), m_mp(50) {}
    Knight(std::string name, int level=1, int hp=100, int mp=50) {
        m_level = level;
        m_name = name;
        m_hp = hp;
        m_mp = mp;        
    }
    //getter, setter
    std::string getName() { return m_name; }
    int getLevel() { return m_level; }
    int getHp() { return m_hp; }
    int getMp() { return m_mp; }
    void setName(std::string name) { m_name = name; }
    void setLevel(int level) { m_level = level; }
    void setHp(int hp) { m_hp = hp; }
    void setMp(int mp) { m_mp = mp; }

    //3. 멤버메소드
    std::string attack() {
        return(m_name + "이(가) 손과 발로 공격!n");
    }
    std::string attack(std::string weapon) {
        return(m_name + "이(가) " + weapon + " 공격!");
    }
    std::string attack(std::string weapon, std::string aura) {
        return(m_name + "이(가) " + weapon + "에" + aura + "을(를) 감싼 후 공격!");
    }
    std::string eat() {
        return(m_name + "이(가) 먹는다.! \n");
    }
};

int main()
{
    //Knight 클래스 타입의 객체(인스턴스) 생성
    Knight k1("제임스", 1, 100, 100);
    std::cout << "이름: " << k1.getName() << std::endl;
    std::cout << "레벨: " << k1.getLevel() << std::endl;
    std::cout << "체력: " << k1.getHp() << std::endl;
    std::cout << "마력: " << k1.getMp() << std::endl << std::endl;
    std::cout << k1.attack() << std::endl;
    std::cout << k1.attack("용살검") << std::endl;  
    std::cout << k1.attack("용살검", " 마기") << std::endl;  
    return 0;
}

