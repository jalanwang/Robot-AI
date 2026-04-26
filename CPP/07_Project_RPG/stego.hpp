#pragma once
#include <iostream>

#include "dinosaur.hpp"
using namespace std;

class Stego : public Dinosaur
{
public:
    string Attack() override {
        return "스테고가 공격하다!!!";
    }
    string Attack(string weapon) override{
        return "스테고가 " + weapon + "(으)로 공격하다!!!";
    }
};
