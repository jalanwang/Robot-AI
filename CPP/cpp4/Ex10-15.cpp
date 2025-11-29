//auto 사용법
//람다 연습
//for_each() 함수와 람다 표현식 사용 예제

#include <iostream>  
#include <string>  
#include <vector>
#include <algorithm>


void print(int n) {
    std::cout << n << " ";
}
int main()
{
    std::vector<int> vec={1,2,3,4,5};
    std::for_each(vec.begin(), vec.end(), print);
    std::cout << std::endl;
    std::for_each(vec.begin(), vec.end(),
    [](int n){std::cout <<n<<" ";});

    return 0;
}

