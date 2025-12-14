/************************************************************************
비정기적인 홈웍 점수를 산술평균값이 아닌 중간값을 이용해서 성적을 산출하려고 함
중간 20%, 기말 40, 홈웍 40%
단 홈웍점수는 중간값을 사용한다.
*************************************************************************/
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

int main() {

        std::cout << "학생의 이름: ";
        std::string name;
        std::cin >> name;
        
        std::cout << "학생 " << name << "의 중간고사 및 기말고사 점수를 입력하시오: ";
        double midterm, final;
        std::cin >> midterm >> final;

        std::cout << "학생의 과제 점수를 모두 입력하시오 :" "끝내려면 Ctrl+D 키를 누르시오.";
        std::vector<double> homework;
        double score;

        while(std::cin >> score) { // 이 부분을 함수로 만들어서 처리하려면 p90-2.cpp를 참조
            homework.push_back(score);            
        }

        typedef std::vector<double>::size_type vec_sz; //p90-1.cpp 참조
        vec_sz size = homework.size();

        if(size==0) {
            std::cout << std::endl << "홈웍 점수가 없습니다. " "다시 한 번 입력하세요." << std::endl;
            return 1;
        }

        vec_sz mid = size/2;
        std::sort(homework.begin(), homework.end());
        double median;

        median = (size%2 ==0) ? (homework[mid]+homework[mid-1])/2 : homework[mid];

        std::streamsize prec = std::cout.precision(); // 나중에 원상 복귀를 위해서 값을 저장해 놓음
        std::cout << "학생 " << name << "의 이번 학기 성적은 " << std::setprecision(3) <<
            0.2*midterm + 0.4*final+0.4*median << std::setprecision(prec) << std::endl;

        return 0;

}

