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

def score_sum(student):
    score_sum=student['Korean']+student['math']+student['english']+student['science']
    return score_sum

def score_average(student):
    score_average=score_sum(student)/4
    return score_average

def student_info(student):
    return(f"{student['name']}\t{score_sum(student)}\t{score_average(student)}\t")

students=[
    create_student("윤이성", 87, 98, 88, 99),
    create_student("연하진", 88, 99, 88, 100)
    ]

print("이름", "총점", "평균", sep='\t')

for student in students:
    print(student_info(student))


# 키를 중복해서 넣을 필요가 없다.
## 학생객체와 학생들 객체를 나눠서 생각하기 시작했다.
### 학생의 총점과 평균을 학생객체에 넣어서 생각하려고 했다.
### 출력도 학생객체가 담당하려고 했다.
### student라는 전역변수에 의존하고 있다.
### 그래서 함수와 객체와의 연결성이 보장되지 않는다.
#### 함수의 매개변수로 student 객체를 넣어서 연결했다.
#### 그런데 마지막 print_score의 리턴이 없다.
#### 출력 담당은 외부에서 처리하는 것일 좋다. 출력을 파일로도 웹으로도 보내야 하기 때문.
