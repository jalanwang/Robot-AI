#include <iostream>
#include <cstdlib>
#include <memory>


class Hero {
  private:
  public: 
  virtual void mAttack() {
    std::cout << "영웅이 공격합니다!" << std::endl;
  }
};

class Knight : public Hero {
  private:
  public:
  void mAttack() override {
    std::cout << "검으로 공격합니다!" << std::endl;
  }
};

class Archer : public Hero {
  private:
  public:
  void mAttack() override {
    std::cout << "활로 공격합니다!" << std::endl;
  }
};

class Wizard : public Hero {
  private:
  public:
  void mAttack() override {
    std::cout << "마법으로 공격합니다!" << std::endl;
  }
};

int main() {  
  
  std::unique_ptr<Hero> knight = std::make_unique<Knight>();
  std::unique_ptr<Hero> archer = std::make_unique<Archer>();
  std::unique_ptr<Hero> wizard = std::make_unique<Wizard>();
   
  knight->mAttack();
  archer->mAttack();
  wizard->mAttack();
  return 0; 
}