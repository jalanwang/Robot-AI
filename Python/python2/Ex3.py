numbers_for_filter=[1,2,3,4,5]
numbers_for_map=[1,2,3,4,5]
# def is_even(x):
#     return x%2==0

# result=filter(is_even, numbers)

# print(list(result))

result1=filter(lambda x: x%2 ==0, numbers_for_filter)
print(list(result1))

result2=map(lambda x: x%2 ==0, numbers_for_map)
print(list(result2))


