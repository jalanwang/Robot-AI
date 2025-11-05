// 45분 일찍 일어나게 하는 방법

#include <stdio.h>

int main()
{
    int hour, min;
    
    int modifier_hour=24;
    int modifier_min=60;
    
    int early_min=45;
    
    int alarm_hour, alarm_min;
    
    scanf("%d %d", &hour, &min);   
   
    if((min-45)<0) 
    {
        alarm_min=modifier_min+min-early_min;
        hour=hour-1;
        if(hour<0) {
            alarm_hour=modifier_hour+hour;
        }
        else alarm_hour=hour;
    }
    
    else {
        alarm_min=min-early_min;
        alarm_hour=hour;
    }
    
    printf("%d %d", alarm_hour, alarm_min);
    
    return 0;
}
