#입력을 받습니다.
a=input("정수 입력>")
last_character=a[-1]

print(last_character)
#짝수조건
if last_character in "02468":
    print("짝수")

if last_character in "13579":
    print("홀수")
