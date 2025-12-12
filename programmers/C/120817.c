// 문제 설명
// 정수 배열 numbers가 매개변수로 주어집니다.
// numbers의 원소의 평균값을 return하도록 solution 함수를 완성해주세요.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

double solution(int numbers[], size_t numbers_len) {
    double answer = 0;
    double sum=0;
    for(int i=0;i<numbers_len;i++) {
        sum+=numbers[i];
    }
    answer=sum/numbers_len;

    return (int)(answer*2+0.5)/2.0; //
}


int main() {
    int numbers[]={1,2};

    double sol=solution(numbers, sizeof(numbers)/sizeof(int));
    printf("average: %.1lf", sol);

    return 0;
}