#pragma once

#include <iostream>

using namespace std;
class Dinosaur
{
protected:
    string name;
    int level;
    int hp;
    int mp;
    int y;
    int x;
public:
    Dinosaur() : level(1), hp(rand() % 100 + 1), mp(50) {}

    void Position(int y , int x) {
    this->y = y;
    this->x = x;
   }
   int getY() {
       return y;
   }
   int getX() {
       return x;  
   }

    virtual string Attack() {
        return "공룡이 공격하다!!!";
    }
    //virtual string Attack() = 0; //순수가상함수
    virtual string Attack(string weapon) {
        return "공룡이 " + weapon + "(으)로 공격하다!!!";
    }
    //Getter, Setter
    void setHp(int hp){
        this->hp = hp;
    }
    int getHp() {
        return hp;
    } 
};