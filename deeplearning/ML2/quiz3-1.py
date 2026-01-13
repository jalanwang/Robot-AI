import numpy as np

def generate_dog_data(initial_lengths, initial_heights, label, num_samples=200):
    """
    초기 데이터를 바탕으로 정규분포를 따르는 가상 데이터(200개)를 생성.
    """
    # 평균과 표준편차 계산
    length_mean = np.mean(initial_lengths)
    height_mean = np.mean(initial_heights)
    length_std = np.std(initial_lengths)
    height_std = np.std(initial_heights)

    # 정규분포를 이용해 새로운 데이터 생성(표준편차를 3배로 늘려서 에러를 넣어 줌)
    new_lengths = np.random.normal(length_mean, 3*length_std, num_samples)
    new_heights = np.random.normal(height_mean, 3*height_std, num_samples)

    # 데이터와 레이블 생성
    data = np.column_stack((new_lengths, new_heights))
    labels = np.full(len(data), label)
    
    return data, labels, new_lengths, new_heights

# 닥스훈트의 길이와 높이 데이터
dach_length_tiny = [55, 57, 64, 63, 58, 49, 54, 61]
dach_height_tiny = [30, 31, 36, 30, 33, 25, 37, 34]

# 진돗개의 길이와 높이 데이터
jin_length_tiny = [56, 47, 56, 46, 49, 53, 52, 48]
jin_height_tiny = [52, 52, 50, 53, 50, 53, 49, 54]

#print(d_data)
#print(d_label)
#print(j_data)
#print(j_label)

d_data, d_label, dach_length, dach_height = \
    generate_dog_data(dach_length_tiny, dach_height_tiny, 0) # 닥스훈트는 0으로 레이블링
j_data, j_label, jin_length, jin_height = \
    generate_dog_data(jin_length_tiny, jin_height_tiny, 1) # 진돗개는 1로 레이블링

# 닥스훈트와 진돗개 데이터를 합쳐 전체 데이터셋 생성
dogs = np.concatenate((d_data, j_data))
labels = np.concatenate((d_label, j_label))
dog_classes = {0:'닥스훈트', 1:'진돗개'}
#print(dogs)
#print(labels)

from sklearn.model_selection import train_test_split # 데이터 분할
X_train, X_test, y_train, y_test = \
    train_test_split(dogs, labels, test_size=0.2, random_state=42)
    # 데이터셋을 훈련용과 테스트용으로 분할. 8:2 비율, random_state는 난수 시드

from sklearn.neighbors import KNeighborsClassifier
k=3 # 인접 데이터의 개수
knn=KNeighborsClassifier(n_neighbors=k) #k-NN 분류기 생성
knn.fit(X_train, y_train) # 모델 학습

# 테스트 데이터로 모델 정확도 평가
score = knn.score(X_test, y_test)
print(f'K-NN모델의 정확도: {score:.2f}')

# 출력 및 저장
import matplotlib.pyplot as plt
plt.scatter(dach_length, dach_height, c='r', label='Dachshund')
plt.scatter(jin_length, jin_height,c='b',marker='^', label='Jindo dog')

plt.xlabel('Length')
plt.ylabel('Height')
plt.title("Dog size")
plt.legend(loc='upper right')

plt.savefig('quiz3-1.png')
print("그래프가 'quiz3-1.png' 파일로 저장되었습니다.")