#include <iostream>
#include <memory>
#include <cstdlib>
#include <vector>

class Hero {
protected:
public:
    virtual void attack() {
        std::cout << "영웅의 공격!" << std::endl;
    }
};

class Knight : public Hero {
public:
    void attack() override {
    std::cout << "기사의 공격!" << std::endl;
    }
};
class Wizard: public Hero {
public:
    void attack() override {
    std::cout << "마법사의 공격!" << std::endl;
    }       
}; 

int main() {
    
    // std::vector<Hero*> list; //업캐스팅
    // list.push_back(new Hero());
    // list.push_back(new Knight());
    // list.push_back(new Wizard());
    
    // for (Hero* hero : list) {
    //     hero->attack();
    //     delete hero;
    // }

    Hero* list[3];
    list[0] = new Hero();
    list[1] = new Knight();
    list[2] = new Wizard();
    for (int i = 0; i < 3; ++i) {
        list[i]->attack();
        delete list[i];
    }       

    return 0;
}     

