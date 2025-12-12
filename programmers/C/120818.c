// 문제 설명
// 머쓱이네 옷가게는 10만 원 이상 사면 5%, 30만 원 이상 사면 10%, 50만 원 이상 사면 20%를 할인해줍니다.
// 구매한 옷의 가격 price가 주어질 때, 지불해야 할 금액을 return 하도록 solution 함수를 완성해보세요.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int price) {
    int answer = 0;
    double rate=0;
    if(price >=500000) {
        rate=0.2;
    }
    else if(price >= 300000) {
        rate=0.1;
    }
 else if(price >= 100000) {
        rate=0.05;
    }    

    return (price*(1-rate));
}


int main() {
    int price = 1000000;
    double sol=solution(price);
    printf("새로운 가격은: %.1lf", sol);

    return 0;
}