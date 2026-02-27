#다음 반복문 내부에 if 조건문의 조건식을 채워서
# 
#  100이상의 숫자만 출력하게 만들어 보이시오.else

numbers=[273, 103, 5, 32, 65, 9, 72, 800, 99]

for number in numbers:
    if number>=100:
        print("{:10d}".format(number))
