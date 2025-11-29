#include <iostream>

class Person{
private:
    int id;
    std::string name;

public:
    Person() {
        this->id = 0;
        this->name = "NoName";
    }

    Person(int id, std::string name) {
        this->id = id;
        this->name = name;
    }    

    void setId(int id) {
        this->id = id;
    }
    
    int getId() {
        return this->id;
    }
    
    void setName(std::string name) {
        this->name = name;
    }

    std::string getName() {
        return this->name;
    }
};

int main() {
    Person sam;
    sam.setId(1888);
    sam.setName("Sam");
    std::cout << "ID: " << sam.getId() << ", Name: " << sam.getName() << std::endl;
    
    return 0;
}