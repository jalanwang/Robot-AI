// 문제 설명
// 정수 배열 numbers와 정수 num1, num2가 매개변수로 주어질 때,
// numbers의 num1번 째 인덱스부터 num2번째 인덱스까지 자른 정수 배열을 return 하도록
// solution 함수를 완성해보세요.

/* 입출력 예
numbers	            num1   num2	    result
[1, 2, 3, 4, 5]	    1	    3	    [2, 3, 4]
[1, 3, 5]	        1  	    2	    [3, 5]
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len, int num1, int num2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(num2*sizeof(int));
    int j=0;

    for(int i=num1-1;i<num1-1+num2;i++) {
        answer[i]=numbers[i];
    }
    return answer;
}


int main() {
    int numbers[]={1,2,3,4,5};
    int* sol=solution(numbers, sizeof(numbers)/sizeof(int), 1,3);
    for (int i=0; i< 0+3; i++) {
        printf("%d ", sol[i]);
    }
    
    return 0;
}