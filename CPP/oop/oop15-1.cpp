#include <iostream>
#include <memory>

class Weapon {
protected:
    int level;
    std::string name;
public:
    Weapon() {
        level = 1;
        name = "무기";    
    }
    
    virtual void attack() {
        std::cout <<"무기로 공격하다!" << std::endl;
    }

    void showLevel() {
        std::cout << "무기 레벨: " << level << std::endl;
    }   

    void showName() {
        std::cout << "무기 이름: " << name << std::endl;
    }  

};

class Sword: public Weapon {
protected:

public:
    Sword() {
        level = 2;
        name = "장검";    
    }

    void attack() override {
        std::cout << name << "으로공격하다!" << std::endl;
    }
};

class Axe: public Weapon {
protected:
public:
    Axe() {
        level = 2;
        name = "도끼";    
    }

    void attack() override {
        std::cout << name << "으로공격하다!" << std::endl;
    }
};

int main() {

    // Weapon* weapon=new Sword();
    // weapon->showName();
    // weapon->showLevel();
    // weapon->attack();  

    // delete weapon;

    Sword sword;
    Sword* swordPtr = &sword;
    

    // std::unique_ptr<Weapon> weapon = std::make_unique<Sword>();
    // weapon->showName();
    // weapon->showLevel();
    // weapon->attack();

    // std::unique_ptr<Sword> sword = std::make_unique<Sword>();
    // sword->showName();
    // sword->showLevel();
    // sword->attack();

    // std::unique_ptr<Axe> axe = std::make_unique<Axe>();
    // axe->showName();
    // axe->showLevel();
    // axe->attack();
    return 0;
}