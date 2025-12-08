array=[1,2,3,"say hello", 5]
for element in array:
    if str(element).isdigit(): 
        print(element)
    else: 
        element.remove()


