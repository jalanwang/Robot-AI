// find number of unique integer number in array.

#include <stdio.h>

int main()
{
    int n=10; //number of index
    int source[n]; 
    int flag; //testmonial integer
    
    int cnt; //number of flags
    int cnt_bar=0; //unique number of each integers
    
    int mod=42; //modular
    
    int arr[n]; //temp array

    for(int i=0;i<n;i++) //calculates remainder of modular(42)
        {
            scanf("%d", &arr[i]);
            source[i]=arr[i]%mod;
        }
    
    for(int i=0;i<n;i++)
    {
        flag=source[i];
        for(int j=i+1;j<n;j++)
        {
            if((flag!=-1) && (flag==source[j])) source[j]=-1;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(source[i]==-1) cnt_bar++;
    }
    cnt=n-cnt_bar;
    
    printf("%d", cnt);
    
    return 0;
}
