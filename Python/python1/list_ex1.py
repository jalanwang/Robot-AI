array=[1,2,3,"say hello", 5]
for element in array:
    if element.isdigit(): 
        pass
    else: 
        element.remove()

print(array)
