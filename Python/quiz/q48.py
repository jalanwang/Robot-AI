#리스트에 들어가 있는 숫자가 유니크키를 가질 때,
#각 숫자의 갯수를 구하시오

#답찾기는 어렵고 알고나면 쉽고!!!!

numbers=[1,2,6,8,4,3,2,1,9,5,4,9,7,2,1,3,5,4,8,9,7,2,3]
counter={}

for number in numbers :
    if number in counter:
        counter[number]+=1
    else :
        counter[number]=1

print(counter)
