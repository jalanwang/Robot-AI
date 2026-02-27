#include <iostream>
#include <memory>
class string {
//	.....	
public:
	string(); // 빈 문자열을 가진 스트링 객체 생성
	string(char* s); // ‘\0’로 끝나는 C-스트링 s를 스트링 객체로 생성
    string(string& str); // str을 복사한 새로운 스트링 객체 생성
//	.....
};

string str; // 빈 문자열을 가진 스트링 객체
string address("서울시 성북구 삼선동 389"); 
string copyAddress(address); // address의 문자열을 복사한 별도의 copyAddress 생성

// class Calculator {
//     public:
//     int big(int a, int b) {
//         if (a>b) return a;
//         else return b;
//     }

//     int big(int a[], int size) {
//         int res=a[0];
//         for(int i=0;i<size;i++) {
//             if(res<a[i]) res=a[i];
//         }
//         return res;
//     }
// };

// int main() {
//     int array[5]={1,9,-2, 6,8};

//     auto calc=std::make_unique<Calculator>();
//     std::cout << calc->big(2,3) <<std::endl;
//     std::cout << calc->big(array,5)<<std::endl;

// }