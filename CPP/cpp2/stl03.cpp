#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
    

int main() {
    std::vector<std::string> stvec;

    std::string name;
    std::cout << "5명의 이름은?:" << std::endl;

    for(int i=0;i<5;i++) {
        std::getline(std::cin, name);
        stvec.push_back(name);
    }

    std::sort(stvec.begin(), stvec.end());
    
    std::cout << std::endl;
    std::cout << "정렬 후" << std::endl;
    for(std::string s : stvec) {
        std::cout << s << std::endl;
    }   
    // for(int i=0;i<stvec.size();i++) {
    //     std::cout << stvec[i] << std::endl;
    // }

    return 0;
}