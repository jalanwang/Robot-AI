import sqlite3
import os

#dbPath = "/mnt/c/Users/User/databases/test7.db"
#wsl로 가지고 오고 파일과 같은 폴더에 생성토록 변경 함
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
dbPath = os.path.join(BASE_DIR, "test8.db")

class Person:
    def __init__(self, id=None, name="", pnumber=""):
        self.id = id
        self.name = name
        self.pnumber = pnumber

    def __str__(self):
        return f"Person(id={self.id}, name={self.name}, pnumber={self.pnumber})"


class PersonRepository:
    def __init__(self, dbPath: str):
        self.dbPath = dbPath

    def getConnection(self):
        return sqlite3.connect(self.dbPath)

    def createTable(self):
        conn = self.getConnection()
        cur = conn.cursor()

        sql = """
        CREATE TABLE IF NOT EXISTS Person (
            ID INTEGER PRIMARY KEY AUTOINCREMENT,
            Name TEXT NOT NULL,
            Pnumber TEXT NOT NULL
        );
        """

        cur.execute(sql)
        conn.commit()
        conn.close()

    def insert(self, person: Person):
        conn = self.getConnection()
        cur = conn.cursor()

        sql = """
        INSERT INTO Person (Name, Pnumber)
        VALUES (?, ?);
        """

        cur.execute(sql, (person.name, person.pnumber))
        conn.commit()

        person.id = cur.lastrowid
        conn.close()

    def findAll(self):
        conn = self.getConnection()
        cur = conn.cursor()

        sql = "SELECT ID, Name, Pnumber FROM Person ORDER BY ID;"
        cur.execute(sql)

        persons = []
        for row in cur:  # (ID, Name, Pnumber)
            persons.append(Person(row[0], row[1], row[2]))

        conn.close()
        return persons
    
    def update(self, person: Person):
        conn = self.getConnection()
        cur = conn.cursor()

        sql = """
        UPDATE Person
        SET Name=?, Pnumber=?
        WHERE ID=?;
        """

        cur.execute(sql, (person.name, person.pnumber, person.id))
        conn.commit()
        conn.close()

    def delete(self, id: int):
        conn = self.getConnection()
        cur = conn.cursor()

        sql = "DELETE FROM Person WHERE ID=?;"
        cur.execute(sql, (id,))
        conn.commit()
        conn.close()

def main():
    repo = PersonRepository(dbPath)
    repo.createTable()

    while True:
        print("\n=== Person Address Book ===")
        print("1. 사람 추가")
        print("2. 전체 조회")
        print("3. 수정")
        print("4. 삭제")
        print("0. 종료")

        choice = input("선택: ").strip()

        match choice:
            case "1": # 삽입
                try:
                    name = input("이름: ").strip()
                    if not name:
                        raise ValueError("이름을 입력해야 합니다.")

                    pnumber = input("전화번호: ").strip()
                    if not pnumber:
                        raise ValueError("전화번호를 입력해야 합니다.")

                    person = Person(name=name, pnumber=pnumber)
                    repo.insert(person)
                    print("저장 완료:", person)
                except ValueError as e:
                    print(f"오류: {e}")

            case "2": # 조회
                persons = repo.findAll()
                print("\n--- 전체 목록 ---")
                print(f"{'ID':<5} {'이름':<10} {'전화번호':<15}")
                print("-" * 35)
                for p in persons:
                    print(f"{p.id:<5} {p.name:<10} {p.pnumber:<15}")

            case "3": # 수정
                id_input = input("수정할 ID: ").strip()
                name = input("새 이름: ").strip()
                pnumber = input("새 전화번호: ").strip()
                #정규식을 통한 전화번호 입력 검증 - 모듈 re이용
                #다시 자성할 예정이다.
                
                repo.update(Person(id=int(id_input), name=name, pnumber=pnumber))
                print("수정되었습니다.")

            case "4": # 삭제
                id_input = input("삭제할 ID: ").strip()
                repo.delete(int(id_input))
                print("삭제되었습니다.")

            case "0":
                print("프로그램 종료")
                break

            case _:
                print("잘못된 입력입니다.")


if __name__ == "__main__":
    main()