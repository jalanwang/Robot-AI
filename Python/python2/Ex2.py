str_numbers=['10', '20', '30', '40', '50']
result=map(int, str_numbers) # map함수 설명
print(list(result))

numbers=[1,2,3,4,5]
def func(x):
    return x*2
result=map(func, numbers) # map함수에서 펑션에 대한 설명
print(list(result))

#### 이것이 람다다!!!!
result=map(lambda x: x*3, numbers) # map 함수에 람다 사용. 람바다~~~~ 람바~~ 람람람

print(list(result))