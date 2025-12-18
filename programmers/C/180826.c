// 문제 설명
// 문자열 my_string과 문자 letter이 매개변수로 주어집니다.
// my_string에서 letter를 제거한 문자열을 return하도록 solution 함수를 완성해주세요.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, const char* letter) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int hit=0;

    for(int i=0;my_string[i]!='\0'; i++) {
        if(my_string[i]==*letter) {
            hit++;            
        }
    }
    
    char* answer = (char*)malloc(strlen(my_string)-hit+1);
    int j=0;
    for(int i=0;my_string[i]!='\0';i++) {
        if(my_string[i]!=*letter) {
            answer[j++]=my_string[i];
        }
    }
    answer[j] = '\0';

    return answer;
}

int main() {
    
    char my_string[]="abfcdef";
    const char* letter="f";
    
    char* sol=solution(my_string, letter);
    
    printf("%s", sol);
    free(sol);

    return 0;
}