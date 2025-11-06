//3개의 주사위 게임

#include <stdio.h>

int main() {
    
    int dice[3];
    int point;
    int max;
    int match;
    
    scanf("%d %d %d", &dice[0], &dice[1], &dice[2]);
    
    //point
    //3 matches 1st prize(10,000) + match_number*1,000
    //2 matches 2nd prize(1,000) + match_number*100
    //no mathes no_prize + biggest_number*100
    
    // if((dice[0]==dice[1])&&(dice[1]==dice[2])&&(dice[2]==dice[0])) {
    //     match=dice[0];
    //     point=10000+match*1000;
    // }

    if(((dice[0]-dice[1])==0)&&((dice[2]-dice[0]==0))) {
        match=dice[0];
        point=10000+match*1000;
    }
    
        
    // else if((dice[0]==dice[1])&&(dice[0]!=dice[2])) {
    //     match=dice[0];
    //     point=1000+match*100;
    // }
    // else if((dice[1]==dice[2])&&(dice[1]!=dice[0])) {
    //     match=dice[1];
    //     point=1000+match*100;
    // }
    // else if((dice[2]==dice[0])&&(dice[2]!=dice[1])) {
    //     match=dice[2];
    //     point=1000+match*100;
    // }
    
    else if((dice[0]==dice[1]) || (dice[1]==dice[2]) || (dice[2]==dice[0])) {
        if(dice[0]==dice[1]) match=dice[0];
        else match=dice[2];
        
        point=1000+match*100;
    }
    
    
    else {
        max=dice[0];
        for(int i=1;i<3;i++) if(max<dice[i]) max=dice[i];
        match=max;

        point=match*100;
    }
    
    printf("%d", point);
    
    return 0;
}
