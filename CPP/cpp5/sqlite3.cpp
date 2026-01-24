/*
sqlite3
sudo apt install sqlite3 libsqlite3-dev

GUI Workbench = DB Browser -> wsl 경로에 접근 가능 가끔 locked.
최소한의 sql
---------------------------
주속록 DB가 없었음.
C++ sqlite3 CRUD
Robot Embedded -> DB
OOP -> 주소록, 명함관리, 로그관리, sw 상태관리, app 상태 모니터링...

펌웨어, mcu, 센서, 데이터시트
스케줄러, 인터럽트
회로

기계
알고리즘 동역학, 솔레노이드, 유공압

*/

#include <iostream>

class Rect; //전방선언이 중요하다.

class RectManager { // RectManager 클래스 선언
public:
	bool equals(Rect r, Rect s);
};

class Rect { // Rect 클래스 선언
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend bool RectManager::equals(Rect r, Rect s); 
};

bool RectManager::equals(Rect r, Rect s) { 
	if(r.width == s.width && r.height == s.height) return true; 
	else return false;
}

int main() {
	Rect a(3,4), b(3,4);
	RectManager man;
	
	if(man.equals(a, b)) std::cout << "equal" << std::endl;
	else std::cout << "not equal" << std::endl; 
}
