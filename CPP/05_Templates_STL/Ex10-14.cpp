//auto 사용법

#include <iostream>
#include <vector>

int square(int x) {return x*x;}

int main() {
    auto c='a';
    auto pi=3.14;
    auto ten=10;
    auto *p=&ten;

    std::cout << c << " " << pi << " " << ten << " " << *p << std::endl;

    auto ret=square(3);
    std::cout << "ret: " << ret << std::endl;

    std::vector<int> vec={1,2,3,4,5};
    std::vector<int>::iterator it;

    for(it=vec.begin();it!=vec.end();it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for(auto e:vec) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    for(auto it=vec.begin(); it!=vec.end(); it++) {
        std::cout << *it << " ";
    }   
    std::cout << std::endl;


return 0;
}