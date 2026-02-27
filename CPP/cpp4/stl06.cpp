//iterator 연습
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

#include <map>

int main() {

  std::map<std::string, std::string> dic;

  dic.insert(std::make_pair("apple", "사과"));
  dic.insert(std::make_pair("banana", "바나나"));
  dic.insert(std::make_pair("grape", "포도"));


  std::cout << "저장된 단어 갯수" << dic.size() << std::endl;

  std::string word;

  while(true) {
    std::cout << "단어 입력: (종료는 end)";
    std::cin >> word;

    if(word=="end") {
        std::cout << "종료합니다." << std::endl;
        break;
    }

    if(dic.find(word)==dic.end()) {
        std::cout << "사전에 없는 단어입니다." << std::endl;
    } else {
        std::cout << word << "의 뜻은 " << dic[word] << "입니다." << std::endl;
    }
    
  }
}