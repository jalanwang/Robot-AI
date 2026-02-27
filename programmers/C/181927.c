#include <stdio.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len) {
    // 새 배열 크기: 기존 + 1개 원소
    int* answer = (int*)malloc((num_list_len + 1) * sizeof(int));
    if (answer == NULL) {
        return NULL;  // 할당 실패 시
    }
    
    // 기존 배열 복사
    for (size_t i = 0; i < num_list_len; i++) {
        answer[i] = num_list[i];
    }
    
    // 마지막 두 원소 비교해 새 원소 추가
    if (num_list[num_list_len - 1] > num_list[num_list_len - 2]) {
        answer[num_list_len] = num_list[num_list_len - 1] - num_list[num_list_len - 2];
    } else {
        answer[num_list_len] = num_list[num_list_len - 1] * 2;
    }
    
    return answer;
}

int main() {
    int num_list1[] = {2, 1, 6};
    int num_list2[] = {5, 2, 1, 7, 5};
    
    size_t len1 = sizeof(num_list1) / sizeof(int);
    size_t len2 = sizeof(num_list2) / sizeof(int);
    
    int* sol1 = solution(num_list1, len1);
    int* sol2 = solution(num_list2, len2);
    
    if (sol1 != NULL) {
        for (size_t i = 0; i < len1 + 1; i++) {
            printf("%d ", sol1[i]);
        }
        printf("\n");
        free(sol1);
    }
    
    if (sol2 != NULL) {
        for (size_t i = 0; i < len2 + 1; i++) {
            printf("%d ", sol2[i]);
        }
        printf("\n");
        free(sol2);
    }
    
    return 0;
}