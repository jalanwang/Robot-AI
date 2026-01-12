import numpy as np

# 닥스훈트의 길이와 높이 데이터
dach_length_tyny = [55, 57, 64, 63, 58, 49, 54, 61]
dach_height_tyny = [30, 31, 36, 30, 33, 25, 37, 34]
# 진돗개의 길이와 높이 데이터
jin_length_tyny = [56, 47, 56, 46, 49, 53, 52, 48]
jin_height_tyny = [52, 52, 50, 53, 50, 53, 49, 54]

dach_length_mean = np.mean(dach_length_tyny)
dach_height_mean = np.mean(dach_height_tyny)
jin_length_mean = np.mean(jin_length_tyny)
jin_height_mean = np.mean(jin_height_tyny)

dach_length_std = np.std(dach_length_tyny)
dach_height_std = np.std(dach_height_tyny)
jin_length_std = np.std(jin_length_tyny)
jin_height_std = np.std(jin_height_tyny)

dach_length=np.random.normal(dach_length_mean,dach_length_std,200)
dach_height=np.random.normal(dach_height_mean,dach_height_std,200)
jin_length=np.random.normal(jin_length_mean,jin_length_std,200)
jin_height=np.random.normal(jin_height_mean,jin_height_std,200)

d_data = np.column_stack((dach_length, dach_height))
d_label = np.zeros(len(d_data))   # 닥스훈트는 0으로 레이블링

j_data = np.column_stack((jin_length, jin_height))
j_label = np.ones(len(j_data))   # 진돗개는 1로 레이블링

#print(d_data)
#print(d_label)
#print(j_data)
#print(j_label)

dogs = np.concatenate((d_data, j_data))
labels = np.concatenate((d_label, j_label))
dog_classes = {0:'닥스훈트', 1:'진돗개'}
#print(dogs)
#print(labels)

from sklearn.neighbors import KNeighborsClassifier
k=3
knn=KNeighborsClassifier(n_neighbors=k)
knn.fit(dogs, labels)

#숙제1
#가까운 이웃을 시각화하자
newdata = [[59, 35]]
y_pred = knn.predict(newdata)
print('데이터', newdata, ', 판정 결과:', dog_classes[y_pred[0]])
'''위 코드의 결과를 바탕으로 다음과 같이 [[59, 35]]에 대한
분류 결과를 시작적으로 나타내도록 하지. 초록색의 세모 점이
이 데이터이며 이 데이터와 이웃한 세 개의 데이터를 주황색으로 
나타내도록 하자'''
import matplotlib.pyplot as plt

plt.scatter(dach_length, dach_height, c='r', label='Dachshund')
plt.scatter(jin_length, jin_height,c='b',marker='^', label='Jindo dog')

plt.xlabel('Length')
plt.ylabel('Height')
plt.title("Dog size")
plt.legend(loc='upper right')

# 새로운 데이터와 모든 개 사이의 거리 계산
distance_square = np.sum((dogs - newdata) ** 2, axis=1)
#print(distance_square) #[ 41  20  26  41   5 200  29   5 298 433 234 493 325 360 245 482]

# 거리가 가까운 k개의 인덱스 찾기
near_idx = np.argsort(distance_square)[:k]
#print(near_idx) #[7 4 1]

# 가까운 이웃들을 주황색으로 표시
for i in near_idx:
    plt.scatter(dogs[i][0], dogs[i][1], s=200, c='orange', marker='*')

# 새 데이터의 표식은 삼각형(triangle)으로 설정하고, 레이블은 new Data로
plt.scatter(newdata[0][0], newdata[0][1], s=100, marker='^', c='g', label='new Data')

plt.savefig('quiz2.png')
print("그래프가 'quiz2.png' 파일로 저장되었습니다.")