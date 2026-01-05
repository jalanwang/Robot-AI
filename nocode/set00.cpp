// std::set
// 중복된 값을 자동으로 제거해주는 효과가 있다.
#include <iostream> 
#include <set>

int main() {

    std::set<int> nums{1,2,3,4,5};

    nums.emplace(5);
    nums.emplace(5);
    nums.emplace(5);

    nums.emplace(-500);
    nums.emplace(100);
    nums.emplace(2);
    
    for(const int num: nums) {
        std::cout << num << std::endl;
    }    

    return 0;
}