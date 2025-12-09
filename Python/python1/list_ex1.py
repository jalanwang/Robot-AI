# 문자열을 리스트에서 제거하기. 단, 새로운 리스트로 만든다.


array=[1,2,3,"say hello", 5]
new_array = []

for element in array:
    # 타입이 문자열(str)이 아닌 경우만 새 리스트에 추가
    if type(element) != str:
        new_array.append(element)

print(new_array)
                            


