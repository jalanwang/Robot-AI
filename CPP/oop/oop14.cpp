#include <iostream>
#include <memory>

class Hero {
private:
    std::string treasure;

protected:
    int level;
    std::string name;

public:
    int hp;
    
    Hero() : level(10), name("Unknown") {
    }
    std::string getTreasue() { return treasure;}

    int getLevel() { return level; }
};

class Wizard : public Hero {
    public:
    Wizard() {
        name = "Harry Potter";
        level = 50;
        hp = 200;
    }

    void showLevel() {
        std::cout << "레벨: " << level << std::endl;
    }

};

int main() {

    std::unique_ptr<Hero> zeus= std::make_unique<Hero>();

    std::cout << "zeus의 레벨: " << zeus->getLevel() << std::endl;
    std::cout << "zeus의 보물: " << zeus->getTreasue() << std::endl;

    


    return 0;
}
