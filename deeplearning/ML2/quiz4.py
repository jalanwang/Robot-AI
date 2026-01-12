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
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(dogs, labels, test_size=0.2, random_state=42)

from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.svm import LinearSVC

svm = Pipeline([  # 표준 스케일러, 선형 SVM 분류기를 파이프라인에 넘겨줌
    ('scaler', StandardScaler()),
    ('linearSVC', LinearSVC(C=1, loss='hinge', dual=True))
    ])
svm.fit(X_train, y_train)     # 이 svm 파이프라인에 X, y 값을 넣어 학습시킴

# 테스트 데이터로 모델 정확도 평가
score = svm.score(X_test, y_test)
print(f'모델의 정확도: {score:.2f}')

import matplotlib.pyplot as plt

plt.scatter(dach_length, dach_height, c='r', label='Dachshund')
plt.scatter(jin_length, jin_height,c='b',marker='^', label='Jindo dog')

plt.xlabel('Length')
plt.ylabel('Height')
plt.title("Dog size")
plt.legend(loc='upper right')

plt.savefig('quiz4.png')
print("그래프가 'quiz4.png' 파일로 저장되었습니다.")