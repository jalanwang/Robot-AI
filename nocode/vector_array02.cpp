// for 반복문과 벡터
// 2번과 3번의 방식이 어셈블러로 보면 동일하다.

#include <iostream> 
#include <vector>

int main()
{
    std::vector<int> nums{0,1,2,3,4};
    nums.emplace_back(5);

    std::cout << "1. 인덱스를 이용 출력" << std::endl;
    for(std::size_t idx=0;idx<nums.size();idx++) {
        std::cout << nums[idx] << std::endl;        
    }

    std::cout << std::endl;
    std::cout << "2. 포인터를 이용한 출력" << std::endl;
    for(auto itr=nums.begin();itr!=nums.end();itr++) {
        std::cout << *(itr) <<std::endl;
    }

     std::cout << std::endl;
    std::cout << "3. ranged for: 얼라이어스를 통해 출력" << std::endl;
    // ranged for
    for(int& itr : nums) { //얼라이어스를 통해서 복사 없이 출력
        std::cout << itr << std::endl;
    }

   std::cout << std::endl;
    std::cout << "4. ranged for: 값 복사 출력" << std::endl;
    // ranged for
    for(int itr : nums) { //값 복사 출력
        std::cout << itr << std::endl;
    }

    return 0;
}