#include <stdio.h>

int main()
{
    int arr[3]={10, 20, 30};
    int *pa = arr;
    
    printf("배열의 값: ");
    
    for (int i=0;i<3;i++)
    {
//        printf("%d ", *pa);
        printf("%d ", *(pa+i));
    }
    return 0;
}