# 1부터 100까지의 숫자가 있다고 합시다. 이를 다음고 같이 계산한다고 했을 떄, 
#최대가 되는 경우는 어떤 숫자를 곱했을 때인지를 찾아 주세요

max_value=0
i=0
j=0
for i in range(1, 100, 1):
    for j in reversed(range(1, 100,1)):
        if (max < int(i*j)):
            max=i*j
         
print("최대가 되는 경우: {} * {} = {}".format(i,j,max_value))
