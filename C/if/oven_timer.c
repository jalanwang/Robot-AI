#include <stdio.h>

int main() {
    
    int cur_hour, cur_min; //현재 시간
    int operating_min; //동작 분
    
    int end_hour, end_min; //종료 시간
    
    int const mod_hour=24; //시간 단위
    int const mod_min=60; //분 단위
    
    int total_min;
    
    scanf("%d %d", &cur_hour, &cur_min);
    scanf("%d", &operating_min);
    
    total_min=cur_hour*mod_min+cur_min+operating_min;
    
    end_hour=(total_min/mod_min)%mod_min;
    //printf("%d: ", end_hour);
    
    if(end_hour>=24) end_hour-=mod_hour;
    
    end_min=total_min%mod_min;
    
    printf("%d %d", end_hour, end_min);
    
    return 0;
}
