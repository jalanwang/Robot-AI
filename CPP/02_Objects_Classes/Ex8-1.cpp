#include <iostream>
#include <memory>

class Person {
    public: 
    Person() {
        std::cout << "사람이 태어났습니다." << std::endl;
    }
    ~Person() {
        std::cout << "사람이 소멸되었습니다." << std::endl;
    }   
    void Speaking() {
        std::cout << "말을 합니다." << std::endl;        
    }
    void Eating() {
        std::cout << "밥을 먹습니다." << std::endl;        
    }   
    void Walking() {
        std::cout << "걷습니다." << std::endl;        
    }
    void Sleeping() {
        std::cout << "잠을 잡니다." << std::endl;        
    }
};

class Student : public Person {
    public:
    Student() {
        std::cout << "학생이 태어났습니다." << std::endl;
    }
    ~Student() {
        std::cout << "학생이 소멸되었습니다." << std::endl;
    }   
    void Studying() {
        std::cout << "공부를 합니다." << std::endl;        
    }   
};

class StudentWorker : public Student {
    public:
    StudentWorker() {
        std::cout << "학생 근로자가 태어났습니다." << std::endl;
    }
    ~StudentWorker() {
        std::cout << "학생 근로자가 소멸되었습니다." << std::endl;
    }   
    void Working() {
        std::cout << "일을 합니다." << std::endl;        
    }   
};

class Researcher : public Person {
    public:
    Researcher() {
        std::cout << "연구원이 태어났습니다." << std::endl;
    }
    ~Researcher() {
        std::cout << "연구원이 소멸되었습니다." << std::endl;
    }     
    void Researching() {
        std::cout << "연구를 합니다." << std::endl;        
    }

};

class Professor : public Researcher {
    public:
    Professor() {
        std::cout << "교수가 태어났습니다." << std::endl;
    }
    ~Professor() {
        std::cout << "교수가 소멸되었습니다." << std::endl;
    }      
    void Teaching() {
        std::cout << "가르칩니다." << std::endl;        
    }
};

int main() {
    
    // Student st;
    // StudentWorker stw;



    return 0;
}