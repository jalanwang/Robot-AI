#include <iostream>
#include <cstdlib>
#include <memory>

class PersonError {
    private:
    int money;

    public:
    // static int getMoney() {
    //     return money;
    // }

    void setMoney(int money) {
        this->money = money;
    }
    int getMoney() {
        return this->money;
    }

};



// main() 함수
int main() {
PersonError pr;
pr.setMoney(1000);
std::cout << pr.getMoney() << std::endl;

}
