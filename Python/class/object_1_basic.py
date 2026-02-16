students=[
    {"name": "윤이성", "Korean": 87, "math":98, "english": 88, "science":99},
    {"name": "연하진", "Korean": 88, "math":99, "english":88, "science": 100}
     ]

print("이름", "총점", "평균", sep='\t')

for student in students:
    score_sum=student['Korean']+student['math']+student['english']+student['science']
    score_average=score_sum/4

    print(student['name'], score_sum, score_average, sep='\t')

# 키를 중복해서 넣을 필요가 없다.

