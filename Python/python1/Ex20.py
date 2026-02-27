#변수를 선언합니다.
example_list=["요소A", "요소B", "요소C"]

#그냥 출력
print("# 단순 출력")
print(example_list)
print()

# enumerate() 함수 사용
print("# enumerate() 함수 적용 출력")
print(enumerate(example_list))
print()

a = list(enumerate(example_list)) #튜플이 되네? 
print(a)                        #[(0, '요소A'), (1, '요소B'), (2, '요소C')]
                                #튜플을 요소로 갇는 리스트가 된다.

print(a[0])
print(type(a[0]))

print("튜플 리스트 출력하기")
for idx, value in enumerate(example_list): #idx와 value (튜플)
    print("{}번째 요소는 {}입니다.".format(idx+1, value))