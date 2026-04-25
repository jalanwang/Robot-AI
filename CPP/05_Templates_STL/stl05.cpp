//iterator 연습
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
    

int main() {
    std::vector<int > vec;
    for(int i=0;i<3;i++) {
        vec.push_back(i);
    }

    std::cout << "iterator를 이용해서 출력하기: " << std::endl;
    std::vector<int>::iterator it; //포인터 변수!!

    for(it=vec.begin();it<vec.end();it++) { //여기 주의해야 됨. 작동은 되는데 문제가 있음.
        std::cout <<vec.at(*it) << std::endl;;
    }
    
    return 0;
}