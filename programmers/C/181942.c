/*
문제 설명
길이가 같은 두 문자열 str1과 str2가 주어집니다.
두 문자열의 각 문자가 앞에서부터 서로 번갈아가면서 
한 번씩 등장하는 문자열을 만들어 return 하는 solution 함수를 완성해 주세요.

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* str1, const char* str2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int size=strlen(str1)+strlen(str2);
    char* answer = (char*)malloc((size+1)*sizeof(char));
    for(int i=0;i<size/2;i++) {
    answer[2*i]=str1[i];
    answer[2*i+1]=str2[i];
    }

    answer[size]='\0'; //널 문자 삽입

    return answer;
}

int main()
{
    char* str1="aaaaa";
    char* str2="bbbbb";

    char* sol=solution(str1, str2);
    printf("%s\n", sol);
    free(sol);

    return 0;
}