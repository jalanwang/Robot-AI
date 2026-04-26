//정수 벡터 5개의 정수를 입력 받아 저장하고, sort()를 이용해서 내림차순으로 정렬하세요.
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <map>

int main() {
  std::vector<int> v;
  
  std::cout << "정수 입력: ";
  for(int i=0;i<5;i++) {
    int num;
    std::cin >> num;
    v.push_back(num);
  }
  std::cout << "-----------------------------------------------" << std::endl;
  
  std::sort(v.begin(), v.end(), [](int a, int b) { return a>b; }); //람다 표현식
   
  // std::cout << "정렬된 벡터 출력: " << std::endl;
  // std::vector<int>::iterator it;
  // for(it=v.begin(); it!=v.end(); It++) {
  //   std::cout << *it << std::endl;
  // }


  for(int i:v) {
    std::cout << i <<"\t" << std::endl;
  } 
  std::cout << std::endl;
}