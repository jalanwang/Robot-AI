
#include <iostream>
#include <cstdlib>
#include <string>
#include <utility>

using namespace std;

class MagicSpell //순수 추상 클래스, 인터페이스 선언.
{
public:
	virtual void spell() = 0; //순수가상함수.
	virtual ~MagicSpell() = default;
	 // 이건 꼭 넣어줘야 자식 클래스까지 상속되어서 메모리에서 날라갈 때 같이 날라가도록 설정됨.
	 //그런데 여기서는 스택에서만 놀기 때문에 필요 없을것도 같다.
};

class FireSpell : public MagicSpell
{
public:
	void spell() override
	{
		cout << "해리포터가 화염마법으로 공격합니다." << endl;
	}
};

class WaterSpell : public MagicSpell
{
public:
	void spell() override
	{
		cout << "해리포터가 수속성마법으로 공격합니다." << endl;
	}
};


class Character {
private:
	string mName;
	FireSpell mDefaultFireSpell{};  // 기본 화염 마법 보유
									// 브라킷은 있어도 없어도 좋음. 단지 윗쪽 클래스를 그대로 사용해서 오브젝트를 생성했다.

	MagicSpell* mSpellStrategy = &mDefaultFireSpell; // 기본값은 화염으로 설정

public:
	explicit Character(string name)
		: mName(name) {}

	void mSetSpell(MagicSpell& spell) {
		mSpellStrategy = &spell;
		cout << mName << "가 새로운 마법을 선택했습니다." << endl;
	}

	void cast() const {		
		mSpellStrategy->spell();
	} 
};

/*
=== 해리 포터 마법 전투 시뮬레이터 ===
1. 화염 마법 선택
2. 얼음 마법 선택
3. 공격 실행
0. 종료
메뉴 선택 : 3
*/

enum class Menu {
	Exit = 0,
	Fire, //1
	Water, //2
	Attack=3
};

int main()
{
	Character hero("해리포터");
	
	FireSpell fire;
	WaterSpell water;


	cout << "=== 해리 포터 마법 전투 시뮬레이터 ===" << endl;

	while (true) {
		cout << '\n';
		cout << "1. 화염 마법 선택" << endl;
		cout << "2. 수속성 마법 선택" << endl;
		cout << "3. 공격 실행" << endl;
		cout << "0. 종료" << endl;
		cout << "메뉴 선택 : ";
		int input;
		if (!(cin >> input)) {
			cout << "잘못된 입력입니다. 프로그램을 종료합니다." << endl;
			break;
		}

		switch (static_cast<Menu>(input)) {
		case Menu::Exit:
			cout << "게임을 종료합니다." << endl;
			return 0;
		case Menu::Fire:
			hero.mSetSpell(fire); //생성자를 이용해서 스펠을 화염속성으로 변경한다.
			break;
		case Menu::Water:
			hero.mSetSpell(water); //생성자를 이용해서 스펠을 수속성으로 변경한다.
			break;
		case Menu::Attack:
			hero.cast();
			break;
		default:
			cout << "지원하지 않는 메뉴입니다." << endl;
		}
	}
}
