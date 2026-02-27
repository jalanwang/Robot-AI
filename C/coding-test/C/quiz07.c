//1과 100까지의 소수
#include <stdio.h>
#include <string.h>

int main()
{
    int prime;
    for(int i=2;i<=100;i++) {//소수인지 확인할 숫자
        prime=1; //일단 소수라 가정
        for(int j=2;j<100;j++) {
            if(j != i && i%j==0) {
                prime=0;
                break;
            }
        }   
    if(prime==1) printf("%d ", i);
    }
    
    return 0;
}
    