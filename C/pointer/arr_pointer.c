#include <stdio.h>


int main() {
    int (*arr)[3];
    //int* (arr)[3];

 //3개의 정수를 가지는 배열에 대한 포인터
    int a[2][3] = { {1, 2, 3}, {4, 5, 6} };
    arr = a; //2차원 배열 a의 주소를 포인터 arr에 할당 
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", *(*(arr + i) + j)); //포인터 연산을 통해 배열 요소에 접근
        }
        printf("\n");
    }
    return 0;

};
