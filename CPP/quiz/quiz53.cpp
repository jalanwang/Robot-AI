/*
c++로 로또번호 구하기를 해봅시다.
std::stl을 이용해 주세요.

1) stl에서 중복되지 않는 함수를 찾아 처리합니다.
2) stl함수를 이용해 로또 번호를 정렬합니다.
3) class Lotto 를 만들어서 수행되게 만들어 줍니다.﻿
1) 중복허용이 되지않습니다.
2) 로또번호를 정렬해서 출력해 주세요

--------------------------------------
로또번호 : 7 14 22 35 37 45
보너스번호: 13
*/

#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric> //iota 사용위해 필요


class Lotto {
private:
    std::vector<int> numbers;
    int bonus = 0;

public:
    void generateLottoNumbers() {
    //1. 난수발생
    std::random_device rd; //랜덤 디바이스 생성
    std::mt19937 gen(rd()); //랜덤 객체를 매개변수로 생성하여 전달. 먼소리인지? 그럼 gen은 몰까?

    //2. 숫자 생성
    std::vector<int> pool(45);
    std::iota(pool.begin(), pool.end(), 1); //1부터 45까지 숫자 생성. iota 사용법. 
                    //첫번째 매개변수는 시작, 두번째는 끝, 세번째는 시작값. 그럼 1부터 시작해서 45까지 자동으로 채워진다는 뜻인가보다.

    
    //3. 섞기
    std::shuffle(pool.begin(), pool.end(), gen); //난수 발생기를 이용해 섞기.  shuffle 사용법 공부해야... 

    //4. 6개 선택 및 정렬
        numbers.assign(pool.begin(), pool.begin() + 6);
        bonus = pool[6]; // 보너스 번호 집어 넣기
        std::sort(numbers.begin(), numbers.end());
        }
    
        void printNumbers() {
            std::cout << "로또번호: ";
            for (int num : numbers) {
                std::cout << num << " ";
            }
            std::cout << "\n보너스번호: " << bonus << std::endl;
        }
    };

int main() {
     
    //5. 출력
    Lotto lucky;
    lucky.generateLottoNumbers();
    lucky.printNumbers();

    return 0;
}