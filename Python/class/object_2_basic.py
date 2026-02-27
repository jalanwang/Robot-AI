def create_student(name, korean, math, english, science):
    return(
        {
        "name" : name,
        "Korean" : korean,
        "math" : math,
        "english" : english,
        "science" : science
        }
    )

students=[
    create_student("윤이성", 87, 98, 88, 99),
    create_student("연하진", 88, 99, 88, 100)
    ]

print("이름", "총점", "평균", sep='\t')

for student in students:
    score_sum=student['Korean']+student['math']+student['english']+student['science']
    score_average=score_sum/4

    print(student['name'], score_sum, score_average, sep='\t')

# 키를 중복해서 넣을 필요가 없다.
## 학생객체와 학생들 객체를 나눠서 생각하기 시작했다.


