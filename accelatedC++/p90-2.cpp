/* 
    while(std::cin >> score) {
        homework.push_back(score);            
    }

    함수로 처리하기
*/
        
#include <iostream>
#include <vector>

std::istream& read_hw(std::istream& in, std::vector<double>& hw) {
    
    if(in) {
        hw.clear();

        double x;
        while(in>>x)
            hw.emplace_back(x);

        in.clear();
    }
    
    return in;
}