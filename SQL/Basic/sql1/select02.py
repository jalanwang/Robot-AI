import sqlite3

path = "/mnt/c/Users/user/databases/"
conn = sqlite3.connect(path + "test3.db")

conn.row_factory = sqlite3.Row
cur = conn.cursor()

cur.execute("SELECT id, name, pnumber FROM person;")

for row in cur:
    print(row["id"], row["name"], row["pnumber"])

conn.close()