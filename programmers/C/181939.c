#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>


int solution(int a, int b) {
    int answer = 0;
    int order_left = 0;    
    int order_right = 0;
    int tempa=a;
    int tempb=b;
    int modified_value1;    
    int modified_value2;    

    while (tempa > 0){ 
        tempa/=10;
        if(a!=0) order_left++; 
        else break;        
    }

    while(tempb > 0) { 
        tempb/=10;
           if(b!=0) order_right++; 
           else break;     
    }
    
    modified_value1=a;
    printf("%d\n", modified_value1);
    for(int i=0;i<order_right;i++) {
       modified_value1=modified_value1*10;
    }
    modified_value2=b;
    for(int i=0;i<order_left;i++) {
        modified_value2=modified_value2*10;
    }
    int sum1=modified_value1+b;
    int sum2=modified_value2+a;
    
    printf("%d\n", sum1);
    printf("%d\n", sum2);
    
    return (sum1>sum2) ? sum1 : sum2;
}

int main() {
    
    int sol;
    sol=solution(12, 3);

    printf("%d\n", sol);   
   
    return 0;
}