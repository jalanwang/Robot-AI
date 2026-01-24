#include <stdio.h>

int main()
{
    int a=10;
    int *p = &a;
     int *pd;

    pd = p;
    printf("%d\n", *pd);

    return 0;
}