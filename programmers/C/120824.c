// 문제 설명
// 정수가 담긴 리스트 num_list가 주어질 때,
// num_list의 원소 중 짝수와 홀수의 개수를 담은 배열을 return 하도록
// solution 함수를 완성해보세요.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2*sizeof(int));
    int even=0;
    int odd=0;

    for(int i=0;i<num_list_len;i++) {
        if(num_list[i]%2 ==0) even++;
        else odd++;
    }
    answer[0]=even;
    answer[1]=odd;

    return answer;
}

int main() {
    int numbers[]={1,2,3,4,5};
    int size=sizeof(numbers)/sizeof(int);
    int* sol=solution(numbers, size);

    printf("[%d], [%d]", sol[0], sol[1]);
    free(sol);

    return 0;

}