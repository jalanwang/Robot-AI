// p90.cpp typedef 문장의 해석

#include <iostream>
#include <vector>

int main() {
    std::vector<double> scores = {10.5, 20.1, 30.7, 40.2, 50.9};

    // [방법 1] typedef 없이 쓰기 (너무 길어서 가독성이 떨어짐)
    std::vector<double>::size_type len1 = scores.size();
    std::cout << "길이1: " << len1 << std::endl;

    // [방법 2] typedef 사용 (교재 코드 - 옛날 방식이지만 명확함)
    typedef std::vector<double>::size_type vec_sz;
    vec_sz len2 = scores.size();
    std::cout << "길이2: " << len2 << std::endl;

    // [방법 3] using 키워드 사용 (C++11 이상 - 요즘 스타일)
    // typedef보다 읽기 편해서 요즘은 이걸 더 많이 씁니다.
    using sz = std::vector<double>::size_type;
    sz len3 = scores.size();
    std::cout << "길이3: " << len3 << std::endl;

    // [방법 4] auto 사용 (C++11 이상 - 제일 편함)
    // 컴파일러야, 네가 알아서 타입 맞춰라!
    auto len4 = scores.size(); 
    std::cout << "길이4: " << len4 << std::endl;

    return 0;
}