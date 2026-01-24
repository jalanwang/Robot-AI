#다음 반복문 내부에 if 조건문의 조건식을 채워서
# 
#  100이상의 숫자만 출력하게 만들어 보이시오.else

for it_out in range(2,10,1):
    for it_in in range(2,10,1):
        print("{}*{}={:2d}".format(it_out, it_in, it_out*it_in))
    print("========================================")    

