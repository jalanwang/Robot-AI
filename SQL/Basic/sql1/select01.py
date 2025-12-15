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

# 3. SQL 실행
sql = "SELECT id, name, pnumber FROM person;"
cur.execute(sql)

rows = cur.fetchall() # 튜플로 가지고 온다.

for row in rows:
    print(row)

conn.close()

print("쿼리가 실행되었습니다.")