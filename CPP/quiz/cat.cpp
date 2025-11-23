#include <iostream>

class Cat {
private:
    std::string name;
    std::string color;
    int age;
      
public:
    Cat() {}
    Cat(std::string name, std::string color, int age):name("kitty"), color("red"), age(11) {
        //this->name = name;
        //this->color=color;
        //this->age=age;
        }
    
    void setName(std::string name) {
        this->name = name;
    }

    void setColor(std::string color) {
        this->color = color;
    }

    void setAge(int age) {
        this->age=age;
    }

    std::string getName() {
        return this->name;        
    }
    std::string getColor() {
        return this->color;        
    }
    int getAge() {
        return this->age;        
    }

};

int main() {
    Cat myCatInStack;
    myCatInStack.setName("스택에 사는 고양이");
    myCatInStack.setColor("무지게");
    myCatInStack.setAge(1);
    std::cout << "이름: " << myCatInStack.getName() << ", 색깔: "
     << myCatInStack.getColor() << ", 나이: " << myCatInStack.getAge() << "살" << std::endl;

    Cat* myCatInHeap = new Cat(); //Cat 인스턴스를 생성한 후, 힙 메모리를 반환토록 했다.
    myCatInHeap->setName("힙에 사는 고양이");
    myCatInHeap->setColor("회색");
    myCatInHeap->setAge(1);
    std::cout << "이름: " << myCatInHeap->getName() << ", 색깔: "
     << myCatInHeap->getColor() << ", 나이: " << myCatInHeap->getAge() << "살" << std::endl;

    delete myCatInHeap; //힙 메모리 해제

    return 0;
}