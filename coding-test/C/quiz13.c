//값이 중복되지 않고 다음과 같이 로또 번호와 보너스 번호를 출력해 주시오.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand((unsigned int)time(NULL));
     
    int hit;
    int lotto_ball=45;
    int lucky[7]; //7개의 볼이 필요
    int history[7]; //발견된 볼 저장 어레이
    int throw=0;

    hit=rand()%45 +1;
    lucky[0]=hit;
    history[0]=lucky[0];

    for(int i=1;i<7;i++) {
        hit=rand()%45 +1;
        for(int j=0;j<i;j++) {            
            if(lucky[i]==history[j]) throw=1;
        }
        if(throw==1) {
            i--;
            break;
        }
        
        lucky[i]=hit;
        history[i]=lucky[i];
    }
    
    printf("로또 번호 :");
    for(int i=0;i<6;i++)    printf("%d ", lucky[i]);
    printf("\n");
    printf("보너스 번호: %d", lucky[6]);
    
    return 0;
}
    