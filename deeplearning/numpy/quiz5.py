#다차원 배열을 나누어 보자
# arange()를 사용하여 1에서 50까지의 원소를 가지는
# 다차원 배열을 만들자. 이 배열의 원소 50개를
#랜덤하게 섞은 후 80% 데이터는 train_data에 넣고, 나머지 20% 데이터는 test_data라는
#배열에 넣어서 이 두 개의 배열을 반환하는 함수
#train_test_split()을 만들자. 반환된 배열 값을 각각 출력하여라.

import numpy as np

def train_test_split():
    a=np.arange(1,51, 1)
    np.random.shuffle(a)
    print(a)    
    train_data=a[:40]
    test_data=a[40:]
    return train_data, test_data

(x_train, x_test)=train_test_split()
print(x_train)
print(x_test)   
