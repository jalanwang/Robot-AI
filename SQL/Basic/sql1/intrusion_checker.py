# 지금 만들어진 데이타를 웨에 게시할 코드를 작성할 것이다.
# 플라스크를 이용한다.

import os
import sqlite3
from datetime import datetime

class LogDatabase:
    def __init__(self, db_name="firewall_logs.db"):
        self.conn = sqlite3.connect(db_name)
        self.cursor = self.conn.cursor()
        self.create_table()

    def create_table(self):
        self.cursor.execute('''
            CREATE TABLE IF NOT EXISTS logs (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                date TEXT,
                time TEXT,
                incident TEXT,
                level TEXT,
                rule TEXT,
                ip TEXT,
                request TEXT
            )
        ''')
        self.conn.commit()

    def clear_logs(self):
        self.cursor.execute("DELETE FROM logs")
        self.conn.commit()

    def porting_log(self, logs):
        data_to_insert = [
            (
                log['date'], 
                log['time'], 
                log['incident'], 
                log['level'], 
                log['rule'], 
                log['ip'], 
                log['request']
            ) for log in logs
        ]
        self.cursor.executemany('''
            INSERT INTO logs (date, time, incident, level, rule, ip, request)
            VALUES (?, ?, ?, ?, ?, ?, ?)
        ''', data_to_insert)
        self.conn.commit()

    def print_level_summary(self):
        self.cursor.execute("SELECT level, count(*) FROM logs GROUP BY level ORDER BY level")
        rows = self.cursor.fetchall()
        
        print("\n[위험도 레벨별 현황]")
        print(f"{'Level':<10} {'Count':<10}")
        print("=" * 20)
        for row in rows:
            print(f"{row[0]:<10} {row[1]:<10}")

    def print_month_pivot(self):
        # 날짜에서 YYYY-MM 추출하여 조회
        self.cursor.execute("SELECT level, strftime('%Y-%m', date) as month FROM logs")
        rows = self.cursor.fetchall()
        
        # 데이터 집계: {(level, month): count}
        data = {}
        months = set()
        levels = set()
        
        for level, month in rows:
            if not month: continue
            months.add(month)
            levels.add(level)
            data[(level, month)] = data.get((level, month), 0) + 1
            
        sorted_months = sorted(list(months))
        sorted_levels = sorted(list(levels))
        
        print("\n[월별 위험도 레벨 현황 (Pivot)]")
        # 헤더 출력 (LEVEL + 월별 컬럼)
        header = f"{'LEVEL':<15}" + "".join([f"{m:<10}" for m in sorted_months])
        print(header)
        print("-" * len(header))
        
        # 행 출력 (각 레벨별 월별 카운트)
        for level in sorted_levels:
            row_str = f"{level:<15}"
            for month in sorted_months:
                count = data.get((level, month), 0)
                row_str += f"{count:<10}"
            print(row_str)

    def print_repeat_critical_attacks(self):
        self.cursor.execute("SELECT ip, count(*) FROM logs WHERE level = 'CRITICAL' GROUP BY ip HAVING count(*) >= 3 ORDER BY count(*) DESC")
        rows = self.cursor.fetchall()
        
        print("\n[CRITICAL 레벨 반복 공격 IP (3회 이상)]")
        print(f"{'IP Address':<20} {'Count':<10}")
        print("=" * 30)
        for row in rows:
            print(f"{row[0]:<20} {row[1]:<10}")

    def close(self):
        self.conn.close()

def parse_log(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    # First line is header
    # The header line in the example was:
    #        DATE         INCIDENT  LEVEL     RULE     IP            REQUEST 
    # It seems the headers are separated by spaces.
    # However, the data columns don't strictly align with single spaces.
    
    # Let's look at the data structure based on observation:
    # Date Time Incident Level Rule IP Request...
    
    data = []
    for line in lines[1:]: # Skip header
        line = line.strip()
        if not line:
            continue
            
        parts = line.split()
        if len(parts) < 6:
            continue
            
        # Reconstruct based on observed structure
        # 0: Date
        # 1: Time
        # 2: Incident
        # 3: Level
        # 4: Rule
        # 5: IP
        # 6+: Request
        
        # 날짜 포맷 변환 (DD/Mon/YY -> YYYY-MM-DD)
        date_str = parts[0]
        try:
            # 예: 01/Dec/25 -> 2025-12-01
            dt = datetime.strptime(date_str, "%d/%b/%y")
            formatted_date = dt.strftime("%Y-%m-%d")
        except ValueError:
            formatted_date = date_str

        record = { # dictionary에 넣어서 저장함
            "date": formatted_date,
            "time": parts[1],
            "incident": parts[2],
            "level": parts[3],
            "rule": parts[4],
            "ip": parts[5],
            "request": " ".join(parts[6:])
        }
        data.append(record)
        
    return data #리스트를 반환, 단, 안에 있는 데이타는 딕셔너리임

if __name__ == "__main__":
    log_file = os.path.join(os.path.dirname(__file__), 'firewall.log')
    parsed_data = parse_log(log_file)
    
    print(f"Total records parsed: {len(parsed_data)}")
    if parsed_data:
        print("First record sample:")
        print(parsed_data[0])

        # Database operations
        db_path = os.path.join(os.path.dirname(__file__), 'firewall_logs.db')
        db = LogDatabase(db_path)
        
        db.clear_logs() # 기존 데이터 초기화
        print("Saving to database...")
        db.porting_log(parsed_data)
        print("Data saved successfully.")
        
        db.print_level_summary()
        db.print_month_pivot() # 월별 피벗 테이블 출력
        db.print_repeat_critical_attacks()
        db.close()

