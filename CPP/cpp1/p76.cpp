//page76 Accelated C++

#include <iostream>
#include <ios>
#include <string>
#include <iomanip>

int main()
{
    //학생의 이름을 묻고 입력받음
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >>name;
    std::cout << "Hello, " << name << "!" <<std::endl;

    //중간시험과 기말시험의 점수를 묻고 입력받음
    std::cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    std::cin >> midterm >> final;

    //과제점수를 물음
    std::cout << "Enter all your homework grades, "
        "followed by end-of-file: ";
    //지금까지 입력된 과제 점수의 개수와 합
    int count=0;
    double sum=0;

    double x;

    //불변성: 지금까지 count개 점수를 입력받았으며 입력받은 점수의 합은 sum
    while((std::cin >> x)) {
        ++count;
        sum+=x;        
    }

    //결과를 출력
    std::streamsize prec= std::cout.precision();
    std::cout << "Your final grade is " << std::setprecision(2)
        << 0.2 *midterm+0.4*final+0.4*sum/count
        <<std::setprecision(prec) <<std::endl;
    
    
    return 0;
}