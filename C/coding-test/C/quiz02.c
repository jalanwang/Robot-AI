//반복문을 이용하여 정수의 합을 구 봅시다.
#include <stdio.h>

int main()
{
    int sum=0;
    int from=1;
    int to=100;

    for(int i=1;i<=100;i++) {
        sum+=i;
    }
    printf("%d", sum);

    return 0;
}