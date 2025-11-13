#include <stdio.h>

int main(int argc, char* argv[])
{
    int isPrime;

    for(int i=2;i<=100;i++) {
        isPrime=1;
        for(int j=2;j<i;j++) {
            if((i!=j) && (i%j==0)) {
                isPrime=0;
                break;
            }
        }
    if(isPrime==1) printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}
