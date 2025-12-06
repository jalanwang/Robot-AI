//숫자를 입력받아 완전수인지 확인하시오.
#include <stdio.h>
#include <string.h>

int main()
{
    int test;
    int sum=0;
    
    scanf("%d", &test);

    for(int i=1;i<test;i++) {
        if(test%i ==0) sum+=i;
    }

    if(test==sum) printf("Yes\n");
    else printf("No\n");

    return 0;
}
    