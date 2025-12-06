//반복문을 이용하여 정수의 합을 구 봅시다.
#include <stdio.h>

int main()
{
    int score;
    
    printf("N? ");
    scanf("%d", &score);

    if(score>=90) printf("\nA학점입니다");
    else if(score>80) printf("\nB학점입니다");
    else if(score>70) printf("\nC학점입니다");
    else if(score>60) printf("\nD학점입니다");
    else printf("\nF학점입니다");

    return 0;
}