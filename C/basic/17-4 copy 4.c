//완전수란 자신을 제외한 약수의 합이 자신이 되는 수를 완전수라고 합니다. 6은 완전수입니다.
//6의 약수는 1 2 3 6 이 중 자신을 제외한 약수의 합 1 + 2 + 3 = 6 즉, 6은 완전수입니다.
//1000 이하의 완전수를 입력 받아 yes, no로 표현해 주세요.

#include <stdio.h>

int main()
{
    int test;
    int tested=0;

    scanf("%d", &test);
    int arr[test];



    int i=1;
    while(i<=test)
    {
        if(test%i==0) tested+=i;
        i++;

    }

    if(test==tested) printf("%d는 완전수입니다.", test);
    else printf("%d는 완전수가 아닙니다", test);


}


