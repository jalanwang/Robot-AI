
#include <iostream>
#include <string>
struct studentInfo
{
    char bloodType;
    int stdNumber;
    double grade;
};

typedef struct studentInfo StudentInfo;

int main()
{
    
    StudentInfo si1={'O', 20031128, 3.5};
    StudentInfo si2={'A', 19961128, 2.3};
    
    std::cout << si1.bloodType + ' ';
    std::cout << si1.stdNumber + ' ';
    std::cout << si1.grade << std::endl;

    std::cout << si2.bloodType + ' ';
    std::cout << si2.stdNumber + ' ';
    std::cout << si2.grade << std::endl;

    return 0;
}