

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <map>

int main() {
  std::vector<int> v;
  for(int i=0;i<21;i++) {    
    v.push_back(i);
  }
  
  std::vector<int>::iterator it;

  std::for_each
  (v.begin(), v.end(),
    [](int n) {
      if(n%2!=0) std::cout <<n<<" ";
    }
  );

  return 0;
}