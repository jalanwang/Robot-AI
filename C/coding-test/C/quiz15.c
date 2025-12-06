//달팽이 //먹이를 찾아 가는 게임

#include <stdio.h>
#include <stdlib.h>

enum OTW {
    CONT=1, RIGHT, DOWN, LEFT, UP
};

int check_way(int way, int x, int y);
int space[5][5]={0,};

int main()
{
    enum OTW way;

    int cnt=0;
    int x,y; //x,y좌표 사용
    int delx, dely;

    way=RIGHT;
    cnt=1;
    x=0;
    y=0;
    space[y][x]=cnt;
    while(cnt<25) {        
        way=check_way(way,x,y);
        printf("way: %d :x=%d y=%d\n", way, x,y);
        switch(way)
        {
            case RIGHT: //X로 증가
            delx=1;
            dely=0;
            break;
            
            case DOWN: //y로 증가
            delx=0;
            dely=1;
            break;

            case LEFT: //x로 감소
            delx=-1;
            dely=0;
            break;

            case UP: //y로 감소
            delx=0;
            dely=-1;
            break;
        }
        x+=delx;
        y+=dely;        

        space[y][x]=++cnt;
    }
    printf("\n");

    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            printf("%5d", space[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//달팽이는 우측 우선이다.
int check_way(int way, int x, int y)
{
    if(way==RIGHT) {
        if((x!=4) && space[y][x+1]==0) return RIGHT;
        else return DOWN; //x증가중에서 y값 증가 시작
    }
    if(way==DOWN) {
        if((y!=4) && space[y+1][x]==0) return DOWN;
        else return LEFT; //y증가중에서 x값 감소 시작
    }
    if(way==LEFT) {
        if ((x!=0) && space[y][x-1]==0) return LEFT;
        else return UP; //x감소중에서 y값 감소 시작
    }
    if(way==UP) {
        if((y!=0) && space[y-1][x]==0) return UP;
        else return RIGHT; //y감소중에서 x값 증가 시작              
    }
}