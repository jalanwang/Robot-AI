#include <stdio.h>

int main() {
    // [지구인] 3명으로 구성된 분대 (12바이트)
    int arr[3] = { 0, 1, 2 }; 

    // [일반 아바타] int형 하나(4바이트)를 가리킴
    int* parr = arr; 

    // [아바타 군단] int 3개짜리 덩어리(12바이트)를 가리킴
    // 괄호(*pbarr)는 "나는 포인터다"라는 선언이고, [3]은 "3칸씩 건너뛴다"는 뜻입니다.
    int(*pbarr)[3] = &arr; 

    printf("=== 1. 주소값 확인 (시작점은 같다) ===\n");
    printf("arr (첫 번째 원소 주소) : %p\n", arr);
    printf("&arr (배열 전체의 주소) : %p\n", &arr);
    // pbarr은 &arr을 담고 있으므로 똑같습니다.
    printf("pbarr (거대 아바타 값)  : %p\n", pbarr); 
    
    printf("\n");

    printf("=== 2. 일반 아바타의 이동 (보폭: 4바이트) ===\n");
    printf("arr     : %p \n", arr);
    printf("arr + 1 : %p (4바이트 증가)\n", arr + 1);
    printf("arr + 2 : %p (8바이트 증가)\n", arr + 2);

    printf("\n");

    printf("=== 3. 아바타 군단의 이동 (보폭: 12바이트) ===\n");
    // &arr은 배열 전체를 하나의 군단으로 봅니다.
    printf("&arr     : %p\n", &arr);
    
    // 여기서 +1은 '다음 분대'로 이동하라는 뜻입니다.
    // int(4byte) * 3개 = 12바이트(0xC) 점프!
    printf("&arr + 1 : %p (12바이트 증가)\n", &arr + 1);
    
    // 12바이트 * 2 = 24바이트(0x18) 점프!
    printf("&arr + 2 : %p (24바이트 증가)\n", &arr + 2);

    return 0;
}