#중복리스트에서 리스트원소를 꺼내어 하나의
#리스토로 만들기
#list_of_list=[[1,2,3], [4,5,6,7], [8,9]]

list_of_list=[[1,2,3], [4,5,6,7], [8,9]]
list1=list_of_list[0]
list2=list_of_list[1]
list3=list_of_list[2]

new_list=list1+list2+list3

for it in new_list:
    print(it)

