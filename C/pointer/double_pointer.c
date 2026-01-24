#include <stdio.h>

int main() {
    int titanic = 100;    // 실제 값
    int *buoy = &titanic; // 부표 (타이타닉의 위치)

    // [나의 시도] 
    // 부표의 위치(&buoy)도 결국 숫자 주소니까, 
    // 그냥 unsigned int 포인터에 담아서 가리켜보자.
    unsigned int *marker = &buoy; 

    // [확인]
    // *marker를 하면 'buoy의 값(타이타닉의 주소)'이 나온다. 여기까지는 성공.
    // 하지만 그 주소로 다시 다이빙(**)을 하려고 하면?
    
    // **marker = 200; // <--- [에러 발생!]
}