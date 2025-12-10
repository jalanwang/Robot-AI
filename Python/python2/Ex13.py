#try exception

list_input_a = ["52", "273", "32", "스파이", "103"]

list_num=[]

for item in list_input_a:
    try:
        float(item)
        #list_num.append(item)
    except:
        pass
    else:
        list_num.append(item)
    finally:
        print("잘 하고 있어요")

print(f"{list_input_a} 내부에 있는 숫자는", end=' ')
print(f"{list_num}입니다.")
