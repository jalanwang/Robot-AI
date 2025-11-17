//값이 중복되지 않고 다음과 같이 로또 번호와 보너스 번호를 출력해 주시오.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand((unsigned int)time(NULL));
     
    int hit;
    const int lotto_ball=45;
    int lucky[7]; //7개의 볼이 필요
    int history=0; //중복이 발견되면 1로 셋팅
    int small;
    hit=rand()%45 +1;
    int ordered_lucky[6];

    lucky[0]=hit;

    for(int i=1;i<7;i++) {
        hit=rand()%lotto_ball +1;

        for(int j=0;j<i;j++) {            
            if(hit==lucky[j]) {
                history=1;
                break;
            }            
        }
        
        if(history==1) {
            i--;
            history=0;            
        }
        
        else {
            lucky[i]=hit;
        }      
    }
    
    small=lucky[0];

    for(int i=0;i<5;i++) { //올림차순정렬
        for(int j=0;j<5;j++) {
            if(lucky[j]>lucky[j+1]) {
                small=lucky[j];
                lucky[j]=lucky[j+1];
                lucky[j+1]=small;
            }

        }      
         
    }
    printf("로또 번호 :");
    for(int i=0;i<6;i++)    printf("%d ", lucky[i]);

    printf("\n");
    printf("보너스 번호: %d", lucky[6]);
    
    return 0;
}
    