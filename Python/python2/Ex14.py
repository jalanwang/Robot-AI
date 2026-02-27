#try, except, else, finally 종합 연습

try:
    number_input_a=int(input("정수 입력"))    
except:
    print("정수를 입력해 달라고 했자눙?")

else:
    print("원의 반지름:", number_input_a)
    print("원의 둘레:", 2*3.14*number_input_a)
    print("원의 넓이:", 3.14*number_input_a)

finally:
    print("일단 잘 돌아 간것 같은데?")
