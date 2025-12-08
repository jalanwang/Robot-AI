array=[1,2,3,"say hello", 5]
for element in array:
    if str(element).isdigit(): 
        print(element)
    else: 
        element.remove() #remove는 값을 찾아서 변경하는거야. 그래서 틀렸네. 
                            #다른 방법을 찾아봐
                            


