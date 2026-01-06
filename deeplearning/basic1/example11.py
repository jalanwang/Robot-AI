import numpy as np
a=np.arange(10)
np.random.shuffle(a)
print(a)

print(np.random.permutation([2,4,6,8,10]))

#다차원 배열을 나누어 보자
#arange()사용하여 1에서 50까지의 원소를 가지는
#다차원 배열을 만들자. 이 배려의 원소 50개를 랜덤하게 섞은 후 80%의 데이타는
#train_data에 넣고 나머지 20% 데이터는 test_data라는 배열에 넣어서
#이 두개의 배열을 반환하는 함수 train_test_split()을 반들자. 반환된 배열 값을 각각 출력하여라.

#만들기
#80% 갯수 만들고 데이타 넣기
#20% 갯수 만들고 데이터 넣기

a=np.arange(1,51,1)
np.random.shuffle(a)
print(a)

def train_test_split():
    train_data=a[0:40]
    #print(train_data)
    test_data=a[40:]
    #print(test_data)
    return train_data,test_data

(x_train, x_test)=train_test_split()
print(x_train)
print(x_test)

# 그레디언트 디센트
# 분산을 구하는 이유는 2차 함수이기 때문이다.
