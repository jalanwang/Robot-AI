// 예외 템플릿, 특수 템플릿

#include <iostream>
#include <cstring>

template <typename T>
bool isEqual(T a, T b) {
    return a == b;
}
// char* 전용 특수화(꼭 추가가 되어야 됨)
template <>
bool isEqual<char*>(char* str1, char* str2) {
    // strcmp를 사용하여 두 문자열이 같으면 true를 반환해야 함
    return strcmp(str1, str2)==0; //strcmp는 같을 때 0을 반환하기 때문
}

int main() {

    char s1[] = "hello";
    char s2[] = "hello";
    std::cout << isEqual(s1, s2) << std::endl; // 결과는 true(1)
    
    char s3[] = "gdbye";
    std::cout << isEqual(s1, s3) << std::endl; // 결과는 false(0)

    return 0;
}

