#with 키워드

# with open('basic2.txt', 'w') as file:
#     file.write('Hello python programming...!')

with open('basic2.txt', 'r') as file:
    rcvd=file.read()

print(rcvd)
