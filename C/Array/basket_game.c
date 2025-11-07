#include <stdio.h>

int main()
{
   int basket_no;
   int batch_no; //영역에 공을 넣는 것을 반복하는 횟수
  
  
   int basket[100]; 
   printf("%d \n", basket[4]); //debug code
   
   int start; //공을 넣을 시작 바구니 번호
   int end; //공을 넣을 끝나는 바구니 번호
   int ball; //공에 적힌 숫자
   
    scanf("%d %d", &basket_no,&batch_no);
   
    for(int i=0;i<batch_no;i++) {
        scanf("%d %d %d", &start, &end, &ball);
        for(int j=start;j<end+1;j++) basket[j-1]=ball;
        //printf("ball: %d\t", ball); //debug code
    }
    
    for(int i=0;i<basket_no;i++) printf("%d \n", basket[i]);
    
    return 0;
}
