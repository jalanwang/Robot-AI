#include <stdio.h>
#include <stdlib.h>

// 문자열 배열의 각 첫 문자를 모아 새 문자열 생성
char* solution(char* num_list[], size_t num_list_len) {
    // 문자열 크기: 각 첫 문자 + 널 종료
    char* answer = (char*)malloc((num_list_len + 1) * sizeof(char));
    if (answer == NULL) {
        return NULL;  // 할당 실패 시
    }
    
    // 각 문자열의 첫 문자 복사
    for (size_t i = 0; i < num_list_len; i++) {
        answer[i] = num_list[i][0];
    }
    
    // 널 종료 추가
    answer[num_list_len] = '\0';
        
    return answer;
}

int main() {
    char* arr[] = {"a", "b", "c"};
    size_t num_list_len = sizeof(arr) / sizeof(arr[0]);

    char* sol = solution(arr, num_list_len);
    if (sol != NULL) {
        printf("%s\n", sol);
        free(sol);
    }
    
    return 0;
}