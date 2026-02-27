// 예외 템플릿, 특수 템플릿

#include <iostream>
#include "generic02.h"

template <typename T>
bool isEqual(T a, T b) {
    return a == b;
}

int main() {

    char s1[] = "hello";
    char s2[] = "hello";
    std::cout << isEqual(s1, s2) << std::endl; // 결과는? 항상 0

    return 0;
}