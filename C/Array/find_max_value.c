// Q13-2) int arr[6]={3,7,2,9,5,1}
// 배열의 최댓값과 index를 구하시오.

#include <stdio.h>

int main() {
    
    int arr[6]={3,7,2,9,5,9};
    int idx=0;
    int max=arr[0];
    
    for(int i=1;i<6;i++) {
        if(arr[i]>=max) {
            max=arr[i];
            idx=i;
        }
    }
    
    printf("max: %d\n",max);
    printf("idx: %d",idx);    
    
    return 0;
}
