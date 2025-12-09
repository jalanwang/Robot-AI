# 1부터 100까지의 숫자가 있다고 합시다. 이를 다음고 같이 계산한다고 했을 떄, 
#최대가 되는 경우는 어떤 숫자를 곱했을 때인지를 찾아 주세요

max_value=0

ordered_list=range(1,100,1)
rev_list=list(reversed(ordered_list)) # list() 함수 사용. [reversed()]하면 안됨.

result=[] #값 없이 초기화. append()로 넣어야 한다.

# 이터레이터를 중복해서 사용하면서 나타난 2개의 문제점. ********
# 1. 인덱스 범위가 맞지 않음.
# 2. 원래 이터레이터로 2개의 리스트에 동시 접근이 안됨
# for it in ordered_list:
#     result.append(it)=it*rev_list[it]
#     if max_value < result[it]:
#         max_value=result[it]
         
for i in range(len(ordered_list)):
    result.append(ordered_list[i]*rev_list[i])
    if max_value<result[i]:
        max_value = result[i]
        max_idx=i+1 #인덱스값 +1이 실재 숫자값

print("최대가 되는 경우: {} * {} = {}".format(max_idx,100-max_idx,max_value))

# 더 간단하게 짜는 경우
# 파이썬도 C의 for문과 비슷하게 짤 수 있군. 괜히 고생했군.
# max_value = 0
# a = 0
# b = 0

# for i in range(1, 100):
#     j = 100 - i
#     if i*j > max_value:
#         max_value = i*j
#         a = i
#         b = j

# print('최대가 되는 경우 : {} * {} = {}'.format(a, b, max_value))
