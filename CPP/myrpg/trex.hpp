#pragma once

#include <iostream>
#include "dinosaur.hpp"

using namespace std;
class Trex : public Dinosaur
{
public:
    string Attack() override {
        return "공룡이 공격하다!!!";
    }
    
    string Attack(string weapon) override {
        return "공룡이 " + weapon + "(으)로 공격하다!!!";
    }   
 
};