//홀수마방진을 만들어 봅시다.
//단, 시작은 첫 행, 중간열에 1을 두고 시작한다.  이건 나중에 다른 위치로 바꿀 수 있다.
//센터자리만 제외.
//숫자의 합은 재귀호출함수를 사용한다.
//중간에 있는 값은 항상 1부터 square 중간이어야 한다.
//합(sum)은 숫자 1부터 square까지의 합이다.
//size*sum=Sum_from_1_to_square.  sum=Sum_from_1_to_square/size.
//처음 찍히는 1과 센터의 중간값을 이용해서 숫자를 만들어가야한다.
//숫자 2개를 제외한 ran(square)+1를 size-2 만큼 만들어서 합을 구해본다.
//합이 일치하면, 1이 지정된 배열과 센터의 중간값을 나타내는 배열을 제외한 곳에 그 값을 집어 넣는다.
//1, 센터값, 마방진을 이루는 가로, 세로, 대각사선좌, 대각사선우를 

#include <stdio.h>
#include <string.h>

void get_match_array(int size, int magic[size][size], int x, int y);
int sum_fuc(int number);

int main()
{
//
    int size;
    int x, y;

    printf("Input the row number of magic square (odd number): ");
    scanf("%d", &size);

    int magic[size][size];
    printf("Where will you put 1? x y");
    scanf("%d %d", &x, &y);
    magic[y-1][x-1] = 1;

    get_match_array(size, magic, x-1, y-1);

    return 0;
}
    
void get_match_array(int size, int magic[size][size], int x, int y)
{
    int square=size*size;
    int i=0;   
    int sum=sum_func(square);
    
    while(i<size) {
    

    for(int m=0;m<square++) {
        for(int j=0;j<size;j++) {
            
                sum+=magic[i][j];
                if(sum==14) {
                    printf("found");
                    magic[i][j]=
                }
        }
    }
    int new_x = x;
    int new_y = y;

}

int sum_func(int number)
{
    if (number == 1)
        return 1;
    else
        return number + sum(number - 1);
}