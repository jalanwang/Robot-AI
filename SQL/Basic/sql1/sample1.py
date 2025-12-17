import sqlite3
import os
import re

# dbPath = "/mnt/c/Users/User/databases/test7.db" /mnt에 두지 않고 
# wsl로 가지고 오고 python 파일과 동일한 폴더에 db를 생성하도록 변경함.
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
dbPath = os.path.join(BASE_DIR, "test8.db")

class Person:
    def __init__(self, id=None, name="", pnumber=""):
        self.id = id
        self.name = name
        self.pnumber = pnumber

    def __str__(self):
        return f"Person(id={self.id}, name={self.name}, pnumber={self.pnumber})"


class PersonRepository: #클래스 이름
    def __init__(self, dbPath: str): #생성자
        self.dbPath = dbPath

    def getConnection(self): #
        return sqlite3.connect(self.dbPath)  #db에 연결

    def createTable(self):
        conn = self.getConnection()
        cur = conn.cursor() #커서를 만들었다. 이 커서에 sql 쿼리가 올라간다.

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

    def insert(self, person: Person): #:Person은 person이 Person클래스의 객체 타입임을 명시하는 역할이다.
        conn = self.getConnection()
        cur = conn.cursor()

        sql = """
        INSERT INTO Person (Name, Pnumber)
        VALUES (?, ?);
        """
        # 파라미터 바인딩(?): ?은 문자가 들어오는 공간이며 sql문이 들어오지 않는 공간.

        cur.execute(sql, (person.name, person.pnumber)) # 파라미터로 person.name, person.pnumber를 튜플로 넣어주는 것같다.
        conn.commit()

        person.id = cur.lastrowid # 마지막으로 생성된 id 값을 person.id로 저장
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
        return persons # 데이타를 뽑아서 persons 리스트에 넘김
    
    def findById(self, id: int): # 수정을 위해서 입력 받은 id가 존재하는 확인하는 함수
        conn = self.getConnection()
        cur = conn.cursor()

        sql = "SELECT ID, Name, Pnumber FROM Person WHERE ID=?;"
        cur.execute(sql, (id,))
        row = cur.fetchone()

        conn.close()
        if row:
            return Person(row[0], row[1], row[2])
        return None

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
        cur.execute(sql, (id,)) # 튜플임을 밝히기 위해서 (id,)를 사용
        row_count = cur.rowcount # 방금 실행된 쿼리의 영향을 받은 행의 갯수를 반환한다.
        conn.commit()
        conn.close()
        return row_count

def main():
    repo = PersonRepository(dbPath)
    repo.createTable() # create table if not exists Person 구절이 있어서 안전하다.

    while True:
        print("\n=== Person Address Book ===")
        print("1. 인명 추가")
        print("2. 전체 조회")
        print("3. 인명 수정")
        print("4. 인명 삭제")
        print("0. 종료")

        choice = input("선택: ").strip()

        match choice:
            case "1": # 삽입
                try:
                    name = input("이름: ").strip()
                    if not name:
                        raise ValueError("이름을 입력해야 합니다.")

                    pnumber = input("전화번호: ").strip()
                    if not re.match(r"^\d{2,3}-\d{3,4}-\d{4}$", pnumber):
                        raise ValueError("전화번호 형식이 올바르지 않습니다. (예: 010-1234-5678)")
                    #^: 문자열의 시작
                    # \d{2,3}: 숫자 2~3자리 (예: 02, 010, 031)
                    # -: 하이픈 문자
                    # \d{3,4}: 숫자 3~4자리
                    # \d{4}: 숫자 4자리
                    # $: 문자열의 끝                    
                 
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
                try:
                    id_input = input("수정할 ID: ").strip()
                    if not id_input.isdigit():
                        raise ValueError("ID는 숫자여야 합니다.")
                    
                    if not repo.findById(int(id_input)):
                        print("수정할 ID가 없습니다.")
                        continue # while 문으로 돌아갑니다.

                    name = input("이름: ").strip()
                    if not name:
                        raise ValueError("이름을 입력해야 합니다.")

                    pnumber = input("전화번호: ").strip()
                    if not re.match(r"^\d{2,3}-\d{3,4}-\d{4}$", pnumber):
                        raise ValueError("전화번호 형식이 올바르지 않습니다. (예: 010-1234-5678)")
                    #^: 문자열의 시작
                    # \d{2,3}: 숫자 2~3자리 (예: 02, 010, 031)
                    # -: 하이픈 문자
                    # \d{3,4}: 숫자 3~4자리
                    # \d{4}: 숫자 4자리
                    # $: 문자열의 끝           
                
                    repo.update(Person(id=int(id_input), name=name, pnumber=pnumber))
                    print("수정되었습니다.")
                except ValueError as e:
                    print(f"오류: {e}")

            case "4": # 삭제
                try:
                    id_input = input("삭제할 ID: ").strip()
                    if not id_input.isdigit():
                        raise ValueError("ID는 숫자여야 합니다.")
                    
                    if repo.delete(int(id_input)) > 0:
                        print("삭제되었습니다.")
                    else: # 삭제할 id가 없으면 반환값이 0임
                        print("삭제할 ID가 없습니다.")
                except ValueError as e:
                    print(f"오류: {e}")

            case "0":
                print("프로그램 종료")
                break # while 문을 깹니다.

            case _:
                print("잘못된 입력입니다.")


if __name__ == "__main__": # main()이 메인펑션임
    main()