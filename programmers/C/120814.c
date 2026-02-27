#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    
    answer=n/7;
    if(n%7 !=0) answer++;
    
    return answer;
}

int main() {
    int sol=solution(15); //15 ppl
    printf("%d", sol);

    return 0;
}