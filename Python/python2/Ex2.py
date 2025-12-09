str_numbers=['10', '20', '30', '40', '50']
result=map(int, str_numbers)
print(list(result))

numbers=[1,2,3,4,5]
def func(x):
    return x*2


#### 이것이 람다다!!!!
#result=map(func, numbers)
result=map(lambda x: x*3, numbers)

print(list(result))