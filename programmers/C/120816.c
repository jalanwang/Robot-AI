// 문제 설명
// 머쓱이네 피자가게는 피자를 두 조각에서 열 조각까지 원하는 조각 수로 잘라줍니다.
// 피자 조각 수 slice와 피자를 먹는 사람의 수 n이 매개변수로 주어질 때,
// n명의 사람이 최소 한 조각 이상 피자를 먹으려면
// 최소 몇 판의 피자를 시켜야 하는지를 return 하도록 solution 함수를 완성해보세요.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int slice, int ppl) {
    int answer = 0;
    int pcs=0;
    // 최소 한 조각은 먹어야 한다.
    // 입력: 2~10pcs
    // 조각 2, 사람: 1 >> 1판
    // 조각 2, 사람: 2 >> 1판
    // 조각 2, 사람: 3 >> 2판 ...
    // 사람 수보다 많은 조각이 있어야 된다. 이를 만족하는 피자의 갯수를 말한다.
    do {
        answer++;
        pcs=slice*answer;
    }
    while(pcs<ppl);
    
return answer;
}

int main() {
    int sol=solution(3,12); //2조각 2 ppl
    printf("%d pizza(s)", sol);

    return 0;
}