#include <stdio.h>

int fact(int N);

int main() {
    
       int number;
       int result;

       scanf("%d", &number);
    
       result=fact(number);
       printf("Factorial of %d = %d",number, result);
       
       return 0;
}

int fact(int N) {
        
        if(N>0) return (N*fact(N-1));
        
        return 1;
}
