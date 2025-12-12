// 문제 설명
// 머쓱이는 추운 날에도 아이스 아메리카노만 마십니다.
// 아이스 아메리카노는 한잔에 5,500원입니다.
// 머쓱이가 가지고 있는 돈 money가 매개변수로 주어질 때,
// 머쓱이가 최대로 마실 수 있는 아메리카노의 잔 수와 남는 돈을 순서대로 담은
// 배열을 return 하도록 solution 함수를 완성해보세요.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int money) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2*sizeof(int));
    answer[0]=money/5500;
    answer[1]=money%5500;
    return answer;
}


int main() {
    int price =34000;
    int* sol=solution(price);
    printf("살수 있는 커피의 갯수: %d / 그리고 잔돈: %d", sol[0], sol[1]);

    return 0;
}