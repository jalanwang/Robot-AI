//배열을 선언하고 랜덤한 숫자를 넣으시오.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand((unsigned int)time(NULL));
     
    int num;
    int arr[5];    

    for(int i=0;i<5;i++) {
        num=rand()%10 +1;
        arr[i]=num;
    }
    
    for(int i=0;i<5;i++) {
        printf("%d ", arr[i]);
    }
    
    
    return 0;
}
    