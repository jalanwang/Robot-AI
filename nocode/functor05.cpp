#define _CRT_SECURE_NO_WARNINGS //인라인 코멘트입니다.
#include <cfloat>

int main(){
    int a;
    int b;
/*
블록 코멘트입니다. 아래 정의는 오류가 납니다.
*/
    const int* pa = &a; // 인라인 코멘트입니다. <<오류 C2166 l-value가 const 개체를 지정합니다.
/* 블록 코멘트 입니다. 위 정의는 오류가 납니다. */
    *pa = 3;
    pa = &b;
    return 0;
}