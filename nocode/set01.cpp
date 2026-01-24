//std::set

#include <iostream> 
#include <set>

struct customFn {
    // operator()를 오버로딩하여 비교 로직을 정의합니다.
    // lhs > rhs로 설정하면 내림차순(큰 수가 앞으로)으로 정렬됩니다.
    bool operator() (const int lhs, const int rhs) const {
        return lhs > rhs;
    }
};

int main() {
    // std::set의 두 번째 템플릿 인자로 우리가 만든 비교 구조체를 전달합니다.
    std::set<int, customFn> nums{1,2,3,4,5};

    for(const int num: nums) {
        std::cout << num << std::endl;
    }

    return 0;
}