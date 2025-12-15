import sqlite3

# 1. 데이터베이스 연결 (없으면 자동 생성)
# 연결객체를 생성. DBMS 회사가 DRIVER와 API를 제공한다.
# SERVER/CLIENT -- FTP, SORI BADA, WEB HARD, MSG SERVICE, MAIL SERVICE, 

# path = "/mnt/c/Users/[UserID]/Code/sql/sqlite/sample1/"
# conn = sqlite3.connect(path + "addressbook.db")

path = "/mnt/c/Users/user/databases/"
conn = sqlite3.connect(path + "test3.db")

# 2. 커서 생성
cur = conn.cursor()

# 3. 테이블 생성 SQL
# create_table_sql = """
# CREATE TABLE IF NOT EXISTS person (
#     id INTEGER PRIMARY KEY AUTOINCREMENT,
#     name TEXT NOT NULL,
#     pnumber TEXT NOT NULL
# );
# """

# 4. SQL 실행
sql = "insert into person (name, pnumber) values ('이순신', '010-111-1111')"
cur.execute(sql)

# 5. 커밋
conn.commit()

# 6. 연결 종료
conn.close()

print("데이터가 입력되었습니다.")