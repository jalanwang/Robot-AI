from flask import Flask, render_template
import sqlite3
import os

# 데이터베이스 경로 설정 (현재 파일과 동일한 위치의 firewall_logs.db)
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
DB_PATH = os.path.join(BASE_DIR, 'firewall_logs.db')

app = Flask(__name__, template_folder=BASE_DIR)

def get_db_connection():
    conn = sqlite3.connect(DB_PATH)
    conn.row_factory = sqlite3.Row
    return conn

@app.route('/')
def index():
    conn = get_db_connection()
    
    # 1. 전체 로그 조회 (날짜, 시간 내림차순)
    logs = conn.execute('SELECT * FROM logs ORDER BY date DESC, time DESC').fetchall()
    
    # 2. 위험도 레벨별 현황
    level_summary = conn.execute('SELECT level, count(*) as count FROM logs GROUP BY level ORDER BY level').fetchall()
    
    # 3. CRITICAL 레벨 반복 공격 IP (3회 이상)
    critical_attacks = conn.execute("SELECT ip, count(*) as count FROM logs WHERE level = 'CRITICAL' GROUP BY ip HAVING count(*) >= 3 ORDER BY count(*) DESC").fetchall()
    
    # 4. 월별 피벗 데이터 (Python에서 처리)
    # SQLite에는 PIVOT 기능이 없으므로 데이터를 가져와서 Python에서 구조화합니다.
    pivot_rows = conn.execute("SELECT level, strftime('%Y-%m', date) as month FROM logs").fetchall()
    
    pivot_data = {} #dcitionary 선언
    months = set() # 집합으로 선언
    levels = set() # 집합으로 선언
    
    for row in pivot_rows:
        lvl = row['level']
        mth = row['month']
        if not mth: continue
        months.add(mth)
        levels.add(lvl)
        # (레벨, 월) 키로 카운트 집계
        pivot_data[(lvl, mth)] = pivot_data.get((lvl, mth), 0) + 1
        
    sorted_months = sorted(list(months))
    sorted_levels = sorted(list(levels))
    
    conn.close()
    
    return render_template('index.html', 
                           logs=logs, 
                           level_summary=level_summary, 
                           critical_attacks=critical_attacks,
                           sorted_months=sorted_months,
                           sorted_levels=sorted_levels,
                           pivot_data=pivot_data)

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000)
