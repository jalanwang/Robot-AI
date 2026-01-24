#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
    

int main() {
    std::vector<int> vec;

    int kor, eng, math; 
    std::cin >> kor >> eng >> math;

    int sum = 0;
    
    double avg; // = sum / 3.0; // 평균인데 여기서 하는게 아님

    vec.push_back(kor);
    vec.push_back(eng);
    vec.push_back(math);
        
    for(int i=0;i<vec.size(); i++) {
        //sum += vec[i];
        sum+=vec.at(i);
    }

    avg=(double)sum/vec.size();

    std::cout << "합계: " << sum << std::endl;
    std::cout << "평균: " << avg << std::endl;
    
    return 0;
}