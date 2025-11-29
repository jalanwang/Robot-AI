#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

class Man {
    public:
    std::string name;
    void studying() {
        std::cout << "공부한다!" << std::endl;
    }
};
class Spider {
    public:
    std::string name;    
    void web() {
        std::cout << "거미줄을 만든다!" << std::endl;
    }   
};
class SpiderMan : virtual public Man, virtual public Spider {};

int main() {

    SpiderMan brilliantbutlazy;
    brilliantbutlazy.studying();
    brilliantbutlazy.web();
    //brilliantbutlazy.name = "해리포터?";
    //std::cout << brilliantbutlazy.name << std::endl;
        
    return 0;
}
