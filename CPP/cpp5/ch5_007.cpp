#include <iostream>
#include <string>

int main() {
	std::string str;
	std::cout << "여러 줄의 문자열을 입력하세요. 입력의 끝은 &문자입니다." << std::endl;
    std::getline(std::cin, str, '&'); //문자열 입력
    std::cin.ignore();
	
    std::string targetStr, replaceStr;

	std::cout << std::endl << "찾을 문자열은?: ";
	std::getline(std::cin, targetStr, '\n'); // 검색할 문자열 입력. 왜 이걸 찾지?
	
    std::cout << "바꿀 문자열:  ";
    std::getline(std::cin, replaceStr, '\n'); // 대치할 문자열 입력

	int idx=0;
	while(true) {
		int i = str.find(targetStr, idx); // 문자열 str에서 find를 이용하여 문자열 targetStr 검색   
		if(i==-1)
			break; // 문자열 str의 끝까지 변경하였음
		str.replace(i, targetStr.length(), replaceStr); // fIndex부터 문자열 f의 길이만큼 문자열 r로 변경
		idx= i+ replaceStr.length(); // 다음 검색은 변경된 문자열 이후부터 시작
	}
	std::cout << str << std::endl;
}
