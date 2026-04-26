#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>


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
  std::vector<std::unique_ptr<Hero>> heroes;
  heroes.push_back(std::make_unique<Knight>());
  heroes.push_back(std::make_unique<Archer>());
  heroes.push_back(std::make_unique<Wizard>());

  for (const auto& hero : heroes) {
    hero->mAttack();
  }

  return 0;
}