// ...existing code...
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <thread>
#include <memory>
#include <chrono>

#include "player.hpp"
#include "dinosaur.hpp"
#include "trex.hpp"
#include "brachio.hpp"
#include "stego.hpp"
#include "veloci.hpp"

#include "story.hpp"
// #include "map.hpp" // map.hpp 제거: 맵 없이 이동 구현

using namespace std;
using namespace std::chrono;

void init_story();
void drawGrid();

int main()
{
    init_story();

    Player p1;
    // 기존 공룡 객체(필요하면 유지)
    Trex t1;
    Stego s1;
    Brachio b1;
    Veloci v1;
    

    // 간단한 맵 없이 이동 구현 (5x5 그리드, 플레이어 위치만 관리)
    const int GRID_SIZE = 5;
    p1.Position(0,0); //플레이어위치 초기화

    // 공룡들의 위치 초기화 (직접 객체 이름으로 호출)
    // 랜덤위치지만 중복방지를 위한 코드를 삽입해야 한다. 미완료
    int lotto = 25; //평면좌표를 0~24사이의 숫자로 변환하여 중복방지 예정
    int history[4]; //4마리 공룡 위치 기록용
    int lucky[4];
    history[0]=0;
    int dump=0;
    int hit=rand()%25+1;
    history[0]=hit;
    for(int i=1;i<4;i++) {
        hit=rand()%25+1;
        for(int j=0;j<i;j++) {
            if(hit==history[j]) dump=1;
        }
        if(dump==1) {
            i--;
            dump=0;
            continue;
        }
    }

    t1.Position(lucky[0]/5, lucky[0]%5);  // Trex 위치
    s1.Position(lucky[1]/5, lucky[1]%5);  // Stego 위치
    b1.Position(lucky[2]/5, lucky[2]%5);  // Brachio 위치
    v1.Position(lucky[3]/5, lucky[3]%5);  // Veloci 위치



    cout << "맵 없이 이동만 하는 모드입니다. 키 입력: w/a/s/d (이동), q (종료)" << endl;
    drawGrid();
    string line;

    while (true) {
        cout << "> " << std::flush;
        if (!getline(std::cin, line)) {
            std::cerr << "\n입력이 종료되었습니다 (EOF). 프로그램을 종료합니다.\n";
            break;
        }
        if (line.empty()) continue;
        char mv = line[0];
        if (mv == 'q') { cout << "종료합니다." << endl; break; }

        int dy = 0, dx = 0;
        switch (mv) {
            case 'w': dy = -1; break;
            case 's': dy =  1; break;
            case 'a': dx = -1; break;
            case 'd': dx =  1; break;
            default: cout << "잘못된 입력입니다. w/a/s/d 또는 q를 사용하세요." << endl; continue;
        }

        int ny = p1.getY() + dy;
        int nx = p1.getX() + dx;
        if (ny < 0 || ny >= GRID_SIZE || nx < 0 || nx >= GRID_SIZE) {
            cout << "경계를 넘을 수 없습니다." << endl;
        } else {
            p1.Position(ny, nx);
            cout << "이동했습니다. 현재 위치: (y=" << p1.getY() << ", x=" << p1.getX() << ")" << endl;
        }
        drawGrid();
    }

    return 0;
}

void init_story()
{
    Story story;
    story.myPrint();
    story.title();    
}

void drawGrid() 
{
    // 그리드 그리기 함수

        std::cout << "Grid:\n";
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                if (p1.getY() == y && p1.getX() == x) std::cout << 'P' << ' ';
                else if (t1.getY() == y && t1.getX() == x) std::cout << 'T' << ' ';
                else if (s1.getY() == y && s1.getX() == x) std::cout << 'S' << ' ';
                else if (b1.getY() == y && b1.getX() == x) std::cout << 'B' << ' ';
                else if (v1.getY() == y && v1.getX() == x) std::cout << 'V' << ' ';
                else std::cout << '.' << ' ';
            }
            std::cout << '\n';
        }


}