#pragma once

#include <iostream>
#include "dinosaur.hpp"

using namespace std;

class Brachio : public Dinosaur
{
public:
    string Attack() override {
        return "브라키오가 공격하다!!!";
    }
    
    string Attack(string weapon) override {
        return "브라키오가 "+ weapon + "(으)로 공격하다!!!";
    }    
};