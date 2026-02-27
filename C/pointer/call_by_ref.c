#include <stdio.h>

void input_array(double *p_array, int size);
double find_max(double *p_array, int size);

int main() {
    double array[5];
    int size, max;    
    
    size=sizeof(array)/sizeof(array[0]);
    //printf("%d", size);
    
    input_array(array, size);
    max=find_max(array, size);
    
    printf("최댓값은: %d", max);
    return 0;
}

void input_array(double *p_array, int size)
{
    for(int i=0;i<size;i++) scanf("%lf", (p_array+i));
}


double find_max(double *p_array, int size)
{
    double max=*p_array;
    
    for(int i=0;i<size;i++) if(max<*(p_array+i)) max=*(p_array+i);
    
    return max;
}

