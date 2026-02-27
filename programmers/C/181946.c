#include <stdio.h>
#include <string.h>

#define LEN_INPUT1 11
#define LEN_INPUT2 11
// 두 문자열을 입력받아 이어 붙여 출력하는 프로그램

int main(void) {
    char s1[LEN_INPUT1];
    char s2[LEN_INPUT2];
    char str[LEN_INPUT1+LEN_INPUT2+1]={'\0',}; // str 배열을 빈 문자열로 초기화

    scanf("%10s %10s", s1, s2);
    
    strncat(str, s1, sizeof(str) - 1); // str에 s1을 이어 붙임. 널 문자도 하나는 넣어야 해서 하나 빼놓음.
    strncat(str, s2, sizeof(str) - 1 - strlen(str)); // str에 s2를 이어 붙임. 남은 공간만큼만 넣기 위해 계산.
    printf("%s\n", str);

    return 0;
}