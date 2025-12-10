# Q59) 다음 함수를 만들어 해결하세요.

# 리스트에서 중복된 값들을 모두 찾아 리스트로 반환하는 함수
# 동일 숫자가 2번 이상 등장하는 항목만 추려내야 한다.
# 중복된 값이 여러 번 있어도 한 번만 결과에 포함한다.
# -------------------------------------------------------------------------------
# numbers = [1, 2, 3, 2, 4, 5, 3, 3, 6]
# find_duplicates(numbers) → [2, 3]

def find_duplicates(dup):
    new_list=[]
    
    for it in dup:
        if dup.count(it)>1 and it not in new_list:
                new_list.append(it)        

    return new_list
    
        
numbers = [1, 2, 3, 2, 4, 5, 3, 3, 6]
sol=find_duplicates(numbers)

print(sol)


# 원래의 리스트에서 하나씩만 있는것을 삭제하는 알고리즘
# 동작 안됨.
# def find_duplicates(dup):
#     new_list=dup    
    
#     for it in dup:
#         if dup.count(it)==1:
#             new_list.remove(it)


#     return new_list    
        
# numbers = [1, 2, 3, 2, 4, 5, 3, 3, 6]
# sol=find_duplicates(numbers)

# print(sol)


