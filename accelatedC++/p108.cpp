/************************************************************************
비정기적인 홈웍 점수를 산술평균값이 아닌 중간값을 이용해서 성적을 산출하려고 함
중간 20%, 기말 40, 홈웍 40%
단 홈웍점수는 중간값을 사용한다.
*************************************************************************/
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

 std::istream& read_hw(std::istream& in, std::vector<double>& hw) {
    if(in) {  
        hw.clear();
       
        double x;

        while(in>>x)
            hw.push_back(x);

        in.clear();
    }
    return in;    
 }
 
 double grade(double midterm, double final, double homework) {
    return 0.2*midterm + 0.4*final+0.4*homework;
 }


 double median(std::vector<double> vec) {
    typedef std::vector<double>::size_type vec_sz;
    vec_sz size = vec.size();

    if(size ==0) {
        throw std::domain_error("vec가 비어 있습니다.");
    }
    
    std::sort(vec.begin(), vec.end());

    vec_sz mid = size/2;
    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
 }

 double grade(double midterm, double final, const std::vector<double>& hw) {
    if(hw.size()==0) {
        throw std::domain_error("학생의 과제 점수가 없습니다.");
    }
    
    return grade(midterm, final, median(hw));
 }

int main() {

        std::cout << "학생의 이름: ";
        std::string name;
        std::cin >> name;
        
        std::cout << "학생 " << name << "의 중간고사 및 기말고사 점수를 입력하시오: ";
        double midterm, final;
        std::cin >> midterm >> final;

        std::cout << "학생의 과제 점수를 모두 입력하시오 :" "끝내려면 Ctrl+D 키를 누르시오.";
        std::vector<double> homework;
        
        read_hw(std::cin, homework);

        try {
            double final_grade=grade(midterm, final, homework);
            std::streamsize prec = std::cout.precision();
            std::cout << "학생 " << name << "의 이번 학기 성적은 " << std::setprecision(3) << final_grade << std::setprecision(prec) << std::endl;
        } catch (std::domain_error e) {
            std::cout << e.what() << std::endl;
            return 1;
        }

        return 0;
}
