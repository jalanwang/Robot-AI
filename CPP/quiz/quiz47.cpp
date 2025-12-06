#include <iostream>
#include <string>
using namespace std;

class Sorceress {
private:
    string name;        // 이름 (필수)
    string leftWeapon;  // 왼손 무기
    string rightWeapon; // 오른손 무기 (방패)
    string leftRing;    // 왼손 반지
    string rightRing;   // 오른손 반지
    string armor;       // 갑옷
    string amulet;      // 목걸이

    // 외부에서 직접 생성하지 못하도록 private 생성자
    Sorceress(const string& name,
            const string& leftWeapon,
            const string& rightWeapon,
            const string& leftRing,
            const string& rightRing,
            const string& armor,
            const string& amulet)
        : name(name),
          leftWeapon(leftWeapon),
          rightWeapon(rightWeapon),
          leftRing(leftRing),
          rightRing(rightRing),
          armor(armor),
          amulet(amulet)
    {
    }

public:
    // === Builder 정의 ===
    class Builder {
    private:
        // 필수 값
        string name;

        // 선택 값들에 기본값 설정
        string leftWeapon  = "맨손";
        string rightWeapon = "맨손";
        string leftRing    = "없음";
        string rightRing   = "없음";
        string armor       = "천 갑옷";
        string amulet      = "없음";

    public:
        // 필수 값은 생성자에서 받도록 강제
        Builder(const string& name)
            : name(name) {}

        // 체이닝 메서드들
        Builder& setLeftWeapon(const string& weapon) {
            leftWeapon = weapon;
            return *this;
        }

        Builder& setRightWeapon(const string& weapon) {
            rightWeapon = weapon;
            return *this;
        }

        Builder& setLeftRing(const string& ring) {
            leftRing = ring;
            return *this;
        }

        Builder& setRightRing(const string& ring) {
            rightRing = ring;
            return *this;
        }

        Builder& setArmor(const string& armorName) {
            armor = armorName;
            return *this;
        }

        Builder& setAmulet(const string& amuletName) {
            amulet = amuletName;
            return *this;
        }

        // 최종 Sorceress 객체 생성
        Sorceress build() const {
            return Sorceress(
                name,
                leftWeapon,
                rightWeapon,
                leftRing,
                rightRing,
                armor,
                amulet
            );
        }
    };

    void print() const {
        cout << "===== 소서리스 장비 상태 =====\n";
        cout << "이름        : " << name << "\n";
        cout << "왼손 무기   : " << leftWeapon << "\n";
        cout << "오른손 무기 : " << rightWeapon << "\n";
        cout << "왼손 반지   : " << leftRing << "\n";
        cout << "오른손 반지 : " << rightRing << "\n";
        cout << "갑옷        : " << armor << "\n";
        cout << "목걸이      : " << amulet << "\n";
        cout << "===========================\n";
    }
};

// 데모용 main
int main() {
    // 1) 소서리스 세팅 예시
    Sorceress element = Sorceress::Builder("원소술사") //왜 연속되어서 실행되는가?
        .setLeftWeapon("스월링크리스탈")   // 왼손: 스피릿
        .setRightWeapon("아마겟돈")     // 오른손: 스피릿 방패
        .setLeftRing("패캐 링")                  // 왼손 반지
        .setRightRing("레번 프로스트")           // 오른손 반지
        .setArmor("수수께끼 아머")               // 갑옷
        .setAmulet("마라의 만화경")              // 목걸이
        .build();

    element.print();

    // 2) 초반 가난한 성기사 예시 (옵션 대부분 기본값 사용)
    Sorceress poorSorce = Sorceress::Builder("무자본원소술사")
        .setLeftWeapon("노멀 마법지팡이")
        .build (); // 나머지 장비는 기본값

    poorSorce.print();

    return 0;
}