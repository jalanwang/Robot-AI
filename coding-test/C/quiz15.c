//달팽이 //먹이를 찾아 가는 게임

#include <stdio.h>
#include <stdlib.h>

int check_way(int way, int x, int y);
int space[5][5]={0,};

int main()
{
    
    int cnt=0;
    int x,y; //x,y좌표 사용
    int way=3; //x로 증가중
    int delx=1;
    int dely=0;

    for(int i=0;i<5;i++) { //초기화 루틴
        for(int j=0;j<5;j++) {
            space[i][j]=0;
        }
    }
     
    x=0;
    y=0;

    delx=1; //우측진행부터
    dely=0; //상하운전 정지
    space[y][x]=1;
    
    while(cnt<26) {        
        way=check_way(way, x+=delx,y+=dely);
        printf("%d :x=%d y=%d\n", way, x,y);
        switch(way)
        {
            case 0: //y로 증가
            delx=0;
            dely=1;
            break;
            
            case 1: //x로 감소
            delx=-1;
            dely=0;
            break;

            case 2: //y로 감소
            delx=0;
            dely=-1;
            break;

            case 3: //x로 증가
            delx=1;
            dely=0;
            break;

            case 4: //그대로 유지           
            break;
        }
        space[y+dely][x+delx]=cnt++;
    }
    printf("\n");

    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            printf("%d ", space[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//달팽이는 우측 우선이다.
int check_way(int way, int x, int y) //0아래 , 1왼쪽, 2위, 3오른쪽
{
    if (way==4 && space[y][x]==0) return 4;
    else if(way==4 && space[y][x]!=0) return 0; //x증가중에서 y값 증가 시작
    else if(way==1 && space[y][x]!=0) return 1; //y증가중에서 x값 감소 시작
    else if(way==2 && space[y][x]!=0) return 2; //x감소중에서 y값 감소 시작
    else if(way==3 && space[y][x]!=0) return 3; //y감소중에서 x값 증가 시작              
}