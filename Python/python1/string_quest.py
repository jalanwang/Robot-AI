#문자열 입력> 안녕하세요
#문자열 입력> 아침입니다.
#안녕하세요. 아침입니다.
#아침입니다. 안녕하세요.

str1 = input("문자열 입력 >")
str2 = input("문자열 입력 >")

#print(str_list1+" "+str_list2)
#print(str_list2+" "+str_list1)

str_list=[str1, str2]


for element_i in str_list: 
    print(element_i)

for element_i in reversed(str_list): 
    print(element_i)

    
