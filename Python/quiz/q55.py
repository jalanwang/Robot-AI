#python if-elif-else구문을 이용해서 성적입력프로그램을 phthon으로 만들어보자

score=int(input("성적을 입력하세요: >"))
if(score >=90):
    print("GradeA")
elif(score >=80):
    print("GradeB")
elif(score >=70):
    print("GradeC")
elif(score >=60):
    print("GradeD")
else :
    print("Fail")