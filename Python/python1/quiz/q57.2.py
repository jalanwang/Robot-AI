#원소의 갯수를 구하시오.
#단 for 이중반복으로 푸시오.

cnt=0
array=[[1,2,3], [4,5,6], [7,8,9]]
for it_row in array:
    for it_col in array:
        cnt+=1

print(cnt)

