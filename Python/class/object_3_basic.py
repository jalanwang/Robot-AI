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

def score_sum():
    score_sum=student['Korean']+student['math']+student['english']+student['science']
    return score_sum

def score_average():
    score_average=score_sum()/4
    return score_average

def print_score():
    print(student['name'], score_sum(), score_average(), sep='\t')

students=[
    create_student("윤이성", 87, 98, 88, 99),
    create_student("연하진", 88, 99, 88, 100)
    ]

print("이름", "총점", "평균", sep='\t')

for student in students:
    print_score()


# 키를 중복해서 넣을 필요가 없다.
## 학생객체와 학생들 객체를 나눠서 생각하기 시작했다.
### 학생의 총점과 평균을 학생객체에 넣어서 생각하려고 했다.
### 출력도 학생객체가 담당하려고 했다.
### student라는 전역변수에 의존하고 있다.
### 그래서 함수와 객체와의 연결성이 보장되지 않는다.
