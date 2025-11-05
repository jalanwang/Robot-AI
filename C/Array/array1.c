#include <stdio.h>

int main() {
    
    int score[5];
    int total=0;
    double avg;
    
    int cnt=sizeof(score)/sizeof(int);
    
    for(int i=0;i<cnt;i++) {
        scanf("%d", &score[i]);
        total+=score[i];
    }
    
    //printf("cnd: %d\n", cnt);
    //printf("total: %d\n", total);
    
    avg=(double)total/cnt;
    printf("%.2lf", avg);

    return 0;
}
