# 이름, 키, 몸무게
# CSV, XML, JSON 방법 등으로 텍스트를 사용해 데이터를 구조적으로 표현

# CSV예시
# 이름, 키, 몸무게
# 윤인성, 176, 62
# 연하진, 169, 50

import random

hanguls=list("가나다라마바사아자차카타파하")

with open('info.csv', 'w') as file:
    for i in range(1000):
        name=random.choice(hanguls)+random.choice(hanguls)+random.choice(hanguls)
        weight=random.randrange(40,100)
        height=random.randrange(140,200)

        file.write(f"{name}, {weight}, {height}\n")


    
