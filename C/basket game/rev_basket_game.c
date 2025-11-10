//basket game
//reverse order of basket in specific range

#include <stdio.h>

int main()
{
    int N;
    int rev_times;
    int start, end;
    int temp;
    
    scanf("%d %d", &N, &rev_times);
    int basket[N];
    int r_basket[N];
    
    for(int i=0;i<N;i++) 
    {
        basket[i]=i+1; //N+1-> N번째
        r_basket[i]=i+1; //복사본
    }
 
        
    for(int i=0;i<rev_times;i++)
    {
        int start, end;
        scanf("%d %d", &start, &end);    
    
        for(int j=start; j<start+(end-start)/2.0; j++) //시작 + 갯수/2
        {
            temp=r_basket[j-1];
            r_basket[j-1]=r_basket[(end-1-(j-start))];
            r_basket[(end-1-(j-start))]=temp; //1, 4
            //r_basket[0]=basket[3] r_basket[1-1]=basket[4-1]
            //r_basket[1] end=[2] r_basket[2-1]=basket[4-1-(j-start)]
            //r_basket[1] end=[3]
            //r_basket[2] end=[2] --> stop point
            //r_basket[3] end=[1]
            //r_basket[4] end=[0]
        }

    }

    for(int i=0;i<N;i++) printf("%d ", r_basket[i]);
    
    return 0;
}





