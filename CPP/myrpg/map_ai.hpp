// ...existing code...
#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <thread>
#include <string>
#include <memory>

#include "dinosaur.hpp"
#include "trex.hpp"
#include "brachio.hpp"
#include "stego.hpp"
#include "veloci.hpp"

class Map {
public:
    static constexpr int SIZE = 5;

    enum Tile { EMPTY = 0, PLAYER = 1, DOCTOR = 2, TREX = 3, BRACHIO = 4, STEGO = 5, VELO = 6 };

    Map() : rng(static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count())) {
        init();
    }

    // 초기화: 플레이어, 닥터, 4마리 공룡을 랜덤한 서로 다른 위치에 배치
    void init() {
        // 빈 그리드
        grid.assign(SIZE, std::vector<int>(SIZE, EMPTY));
        // 모든 좌표 목록 생성
        std::vector<std::pair<int,int>> coords;
        coords.reserve(SIZE * SIZE);
        for (int y = 0; y < SIZE; ++y)
            for (int x = 0; x < SIZE; ++x)
                coords.emplace_back(y, x);

        // 섞고 앞에서 순서대로 배치: player, doctor, dino x4
        std::shuffle(coords.begin(), coords.end(), rng);

        auto it = coords.begin();
        player = *it++; grid[player.first][player.second] = PLAYER;
        doctor = *it++; grid[doctor.first][doctor.second] = DOCTOR;
        dinos.clear();
        for (int i = 0; i < 4 && it != coords.end(); ++i, ++it) {
            // 각 인덱스에 맞는 공룡 서브클래스 인스턴스 생성
            std::shared_ptr<Dinosaur> d;
            int tileType = TREX;
            if (i == 0) { d = std::make_shared<Trex>(); tileType = TREX; }
            else if (i == 1) { d = std::make_shared<Brachio>(); tileType = BRACHIO; }
            else if (i == 2) { d = std::make_shared<Stego>(); tileType = STEGO; }
            else /* i == 3 */ { d = std::make_shared<Veloci>(); tileType = VELO; }

            dinos.push_back({*it, d});
            grid[it->first][it->second] = tileType;
        }
    }

    // 지도 그리기 (콘솔 출력)
    // P = player, H = doctor(의사), D = dinosaur, . = empty
    void draw() const {
        std::cout << "Map:\n";
        for (int y = 0; y < SIZE; ++y) {
            for (int x = 0; x < SIZE; ++x) {
                char c = '.';
                switch (grid[y][x]) {
                    case PLAYER:  c = 'P'; break;
                    case DOCTOR:  c = 'H'; break;
                    case TREX:    c = 'T'; break;
                    case BRACHIO: c = 'B'; break;
                    case STEGO:   c = 'S'; break;
                    case VELO:    c = 'V'; break;
                    default:      c = '.'; break;
                }
                std::cout << c << ' ';
            }
            std::cout << '\n';
        }
    }

    // 플레이어 이동: 'w','a','s','d'
    // 반환값: 이벤트 메시지(아무 이벤트 없으면 빈 문자열)
    std::string movePlayer(char dir) {
        int dx = 0, dy = 0;
        switch (dir) {
            case 'w': dy = -1; break;
            case 's': dy =  1; break;
            case 'a': dx = -1; break;
            case 'd': dx =  1; break;
            default: return "잘못된 입력입니다.";
        }

        int ny = player.first + dy;
        int nx = player.second + dx;

        // 경계 체크
        if (ny < 0 || ny >= SIZE || nx < 0 || nx >= SIZE) {
            return "경계를 넘을 수 없습니다.";
        }

        int target = grid[ny][nx];
        // 이동 처리: 먼저 현재 플레이어 칸 비움
        grid[player.first][player.second] = EMPTY;

        // 닥터를 만난 경우: 닥터 제거(한번만 만남), 이벤트 리턴
        if (target == DOCTOR) {
            player = {ny, nx};
            grid[ny][nx] = PLAYER;
            // 닥터 제거 표시
            doctor = {-1,-1};
            return "닥터를 만났습니다! 체력 회복/상담 이벤트 발생.";
        }

        // 공룡 종류별 처리: TREX, BRACHIO, STEGO, VELO
        if (target == TREX || target == BRACHIO || target == STEGO || target == VELO) {
            player = {ny, nx};
            // 플레이어가 해당 칸을 차지
            grid[ny][nx] = PLAYER;
            // dinos 목록에서 해당 좌표의 공룡 객체 제거(조우로 인해 제거되는 동작)
            removeDinoAt(ny, nx);
            // 만난 공룡 종류별 메시지
            std::string species;
            switch (target) {
                case TREX:    species = "티렉스"; break;
                case BRACHIO: species = "브라키오"; break;
                case STEGO:   species = "스테고"; break;
                case VELO:    species = "벨롭시"; break;
                default:      species = "공룡"; break;
            }
            return species + "를 만났습니다! 전투/회피 이벤트 발생.";
        }

        // 빈 칸이면 그냥 이동
        player = {ny, nx};
        grid[ny][nx] = PLAYER;
        return ""; // 이벤트 없음
    }

    // 현재 플레이어 좌표 반환(디버깅/로직용)
    std::pair<int,int> getPlayerPos() const { return player; }
    std::pair<int,int> getDoctorPos() const { return doctor; }
    const std::vector<std::pair<std::pair<int,int>, std::shared_ptr<Dinosaur>>>& getDinos() const { return dinos; }

private:
    std::vector<std::vector<int>> grid;
    std::pair<int,int> player{0,0};
    std::pair<int,int> doctor{-1,-1};
    // dinos: 좌표 + 실제 Dinosaur 인스턴스(서브클래스)
    std::vector<std::pair<std::pair<int,int>, std::shared_ptr<Dinosaur>>> dinos;
    std::mt19937 rng;

    void removeDinoAt(int y, int x) {
        for (auto it = dinos.begin(); it != dinos.end(); ++it) {
            if (it->first.first == y && it->first.second == x) {
                dinos.erase(it);
                break;
            }
        }
        // grid는 호출자에서 플레이어로 이미 설정되어 있음
    }
};