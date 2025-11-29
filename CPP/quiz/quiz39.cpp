//Q39) 다음 벡터에서 STL 함수를 사용하여 중복을 제거한 후 출력하라.
// vector<int> vec = {1, 1, 1, 2, 2, 2, 3, 3, 3};
// 벡터의 구성이 다음과 같을 때 중복을 제거한 1, 2, 3만 출력되게 만들어 보세요.
// ----------------
// 1
// 2
// 3
// ----------------


#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <map>

int main() {
  std::vector<int> v= {1, 1, 1, 2, 2, 2, 3, 3, 3};

  std::sort(v.begin(), v.end()); //일반화 하기 위해서 정렬 먼저 함.
  // bool unique=false;
  // int history=-1;
  // for(int i=0;i<size(v); i++) {
  //   if(history==v[i]) {
  //     continue;
  //   } else {
  //     std::cout << v[i] << std::endl;
  //     history=v[i];
  //   }
  // }  

  auto it_v=std::unique(v.begin(), v.end()); //중복된 값들은 오른쪽으로 이동하고 중복이 시작된 위치를 이터레이터로 반환한다.
  v.erase(it_v, v.end()); //반환받은 것 부터 끝까지 자른다.

  for(int i: v) {
    std::cout << i << std::endl;
  }

  return 0;
}

