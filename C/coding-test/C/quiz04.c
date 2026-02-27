//변수교환
#include <stdio.h>

void swap(int* n1, int* n2);

int main()
{
    int n1, n2;
  
    scanf("%d %d", &n1, &n2);
    printf("%d %d", n1, n2);
    printf("\n");
    swap(&n1, &n2);
    printf("%d %d", n1, n2);
    
    return 0;
}

void swap(int* n1, int* n2)
{
    int temp;
    temp=*n1;
    *n1=*n2;
    *n2=temp;
}