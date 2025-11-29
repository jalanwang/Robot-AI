#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(k*strlen(my_string)+sizeof(char));
    for(int i=0;i<k;i++) {
        for(int j=0;j<strlen(my_string);j++) {
            answer[j+i*strlen(my_string)]=my_string[j];
        }
    }
    answer[k*strlen(my_string)]='\0'; //널 문자 삽입
    return answer;
}

int main() {
    char* my_string1="string";
    char* my_string2="love";
    int k1=3;
    int k2=7;


    char* sol1=solution(my_string1, k1);
    printf("%s\n", sol1);
    free(sol1); 
    char* sol2=solution(my_string2, k2);
    printf("%s\n", sol2);
    free(sol2); 

}