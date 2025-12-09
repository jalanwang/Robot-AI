#해당하는 특정 값 제거하기

list_test=[1,2,1,2]
value=2

while value in list_test:
    list_test.remove(value)

print(list_test)

##########################################
# filter함수를 써볼까?
##########################################

list_test1=[1,2,1,2,4,5,6,7,8]
value=2 # 홀 짝을 구분짓기 위한 수

odd_list=list(filter(lambda x: x%value!=0, list_test1))

print(odd_list)