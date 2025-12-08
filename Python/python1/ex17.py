key_list=["name", "hp", "mp", "level"]
value_list=["기사", 200, 30, 5]

character={}

i=0
for key in key_list:
    character[key]=value_list[i]
    i+=1

print(character)
