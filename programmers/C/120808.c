//정수 배열 numbers가 매개변수로 주어집니다.
// numbers의 각 원소에 두배한 원소를 가진 배열을 return하도록 solution 함수를 완성해주세요.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(numbers_len*sizeof(int));
    
    for(int i=0;i<numbers_len;i++) {
        answer[i]=2*numbers[i];
    }
    return answer;
}

int main()
{
    int numbers[]={1,2,3,4,5,6};
    int* sol = solution(numbers, 6);
    
    for(int i=0;i<sizeof(numbers)/sizeof(int);i++) {
        printf("%d ", sol[i]);
    }   
    
    free(sol);

    return 0;
}