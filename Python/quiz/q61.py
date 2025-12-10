# 1. 문제 1: 가상 학생 성적 CSV 파일 생성하기
# 다음 조건을 만족하는 코드를 작성하라.

# 조건
# students.csv 파일을 생성한다.

# 학생 수는 30명으로 한다.
# 각 학생은 아래 필드를 가진다.

# id (1~30 번호)
# name (랜덤 한글 2~3글자 조합)
# math 점수 (0~100 랜덤)
# english 점수 (0~100 랜덤)

# CSV 형식으로 저장한다. (콤마 구분)

# id,name,math,english
# 1,박민수,87,74
# 2,김하준,45,93
# ...

import random

data_number =1000
family_name = list("김이박최강고한천유피")
given_name = list("가나다라마바사아자차카타파하")

flag=range(1, 101) #1%가 외자라 가정
with open('student_scores.csv', 'w') as file:
     file.write('id, name, math, english\n')
     for i in range(data_number):
        id=i+1
        f_name=random.choice(family_name)
        if random.choice(flag)!=1:
            g_name=random.choice(given_name)+random.choice(given_name)
        else:
            g_name=random.choice(given_name)        
        
        math_score=random.randrange(101)
        english_score=random.randrange(101)
        file.write(f"{id}, {f_name}{g_name}, {math_score}, {english_score}\n")
    



