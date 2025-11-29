//배열의 합을 구하여 리턴하는 제네릭 add() 함수 만들기 연습
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

int main() {
 
    std::string str;
    getline(std::cin, str);
    std::string str2; //사이즈가 고정된다.

    int cnt=0;
    for(int i=0;i<80;i++) {
        if(str[i]=='\0') {
            cnt=i;        
            break;
        }
    }
    
    std::cout << "for문으로 만든 역 문자열 표시" << std::endl;
    for(int i=cnt;i>=0;i--) {
        if(cnt==0) break;
        //std::cout << str[i];
        std::cout << str.at(i);
    }
    std::cout << std::endl;
    
    //문자열 string 복사
    //문자 캐릭터를 스트링으로 스트링을 캐릭터배열로 변환하는 방법이 중요.
    //strcpy(str, str2.c_str()); //과거에는 요렇케 했다. //icnlude <cstring> 필요했다.

    str2.resize(str.size());

    
    std::cout << "STL로 만든 역 문자열 표시" << std::endl;
    std::reverse(std::begin(str), std::end(str));
    std::cout << str << std::endl;

    return 0;
}
//std::cin으로 받으면 한 번 더 받으면 이상해짐. 플러시를 해주어야 할 듯.
//기억이 안남. 