// 문제 설명
// 정수가 들어 있는 배열 num_list가 매개변수로 주어집니다.
// num_list의 원소의 순서를 거꾸로 뒤집은 배열을 return하도록 solution 함수를 완성해주세요.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(num_list_len*sizeof(int));

    for (int i=0;i<num_list_len;i++) {
        answer[num_list_len-1-i]=num_list[i];
    }

    return answer;
}

int main() {
    int numlist[]={1,2,3,4,5};
    int size=sizeof(numlist)/sizeof(int);
    int* sol=solution(numlist, size);
    
    for(int i=0;i<size;i++) {
        printf("%d ", sol[i]);
    }

    return 0;
}