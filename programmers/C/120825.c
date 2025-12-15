// 문제 설명
// 문자열 my_string과 정수 n이 매개변수로 주어질 때,
// my_string에 들어있는 각 문자를 n만큼 반복한 문자열을 return 하도록
// solution 함수를 완성해보세요.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t len = strlen(my_string);
    char* answer = (char*)malloc(len * n + 1);

    for(size_t i = 0; i < len; i++) {
        for(int j=0;j<n;j++) {
            answer[i * n + j] = my_string[i];
        }
    }
    answer[len * n] = '\0';

    return answer;
}

int main() {
    char my_string[]="hello";
    char* sol=solution(my_string, 3);

    printf("%s\n", sol);
    free(sol);

    return 0;
}