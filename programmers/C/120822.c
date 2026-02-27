// 문제 설명
// 문자열 my_string이 매개변수로 주어집니다. 
// my_string을 거꾸로 뒤집은 문자열을 return하도록 solution 함수를 완성해주세요.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t len = strlen(my_string);
    char* answer = (char*)malloc((len + 1) * sizeof(char));
    for(size_t i = 0; i < len; i++) {
        answer[i] = my_string[len - 1 - i];
    }
    answer[len] = '\0';
    return answer;

}

int main() {
    const char my_string[]="Shall we dance";
    char* sol=solution(my_string);
    printf("%s\n", sol);
    free(sol);

    return 0;
}