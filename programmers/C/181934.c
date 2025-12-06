/*
문제 설명
문자열에 따라 다음과 같이 두 수의 크기를 비교하려고 합니다.

두 수가 n과 m이라면
">", "=" : n >= m
"<", "=" : n <= m
">", "!" : n > m
"<", "!" : n < m
두 문자열 ineq와 eq가 주어집니다.
ineq는 "<"와 ">"중 하나고, eq는 "="와 "!"중 하나입니다.
그리고 두 정수 n과 m이 주어질 때, n과 m이 ineq와 eq의 조건에 맞으면 1을 아니면 0을 return하도록 solution 함수를 완성해주세요.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

int solution(const char* ineq, const char* eq, int n, int m) {
                      
    char ineq_ch = ineq[0];
    char eq_ch = eq[0];

    if (ineq_ch == '>' && eq_ch == '=') {
        return n >= m;
    }
    if (ineq_ch == '<' && eq_ch == '=') {
        return n <= m;
    }
    if (ineq_ch == '>' && eq_ch == '!') {
        return n > m;
    }
    if (ineq_ch == '<' && eq_ch == '!') {
        return n < m;
    }

    return 0;
}

int main() {
    int sol1 = solution("<", "=", 20, 50);
    int sol2 = solution(">", "!", 41, 78);

    printf("%d\n", sol1);
    printf("%d\n", sol2);

    return 0;
}