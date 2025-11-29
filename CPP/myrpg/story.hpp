#pragma once

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

// Helper to print text with a small delay between characters
class Story {
public:
    void DelayPrint(const std::string& text, int delay_ms) const {
        for (char ch : text) {
            std::cout << ch << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
        }
        std::cout << std::endl;
    }

    void myPrint()
    {
        DelayPrint("쥬라식 파크에 오신것을 환영합니다!", 30);
        DelayPrint("공룡과 함께하는 맵 탈출 게임을 즐겨보세요!", 30);
        DelayPrint("단, 왠만해서는 공룡을 이길 수는 없으니 잘 피해다녀 보심!", 30);
        DelayPrint("화이팅!!! ㅋㅋㅋㅋㅋㅋ", 30);
        
    }
    void title()
    {
        std::cout << 
                R"(           
              /_)
    .-^^^-/ /
    __/       /
    <__.|_|-|_|
    )" 
        << std::endl;
  
        // 타이틀 문구 빠르게 출력
        DelayPrint("=== JURASSIC PARK ===", 10);
    }
};