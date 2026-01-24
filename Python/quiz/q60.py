# 1. 문제 1: 짝수만 골라 제곱 리스트 만들기
# 다음 리스트가 있다.
# numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
# 조건
# filter를 사용하여 '짝수'만 걸러라.
# map을 사용하여 '걸러진 값의 제곱'을 계산하라.
# 최종 결과 리스트를 출력하라.
# 예상 출력 형태:
#[4, 16, 36, 64, 100]

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
filtered = filter(lambda x : x%2==0, numbers)
mapped=map(lambda i: i*i, filtered)
print(list(mapped))

# 2. 문제 2: 문자열 리스트에서 길이가 5 이상인 단어의 길이만 뽑아내기
# 다음 문자열 리스트가 있다.
# words = ["python", "map", "filter", "lambda", "hi", "education", "code"]
# 조건
# filter로 길이가 5 이상인 단어만 남겨라.
# map으로 각 단어의 문자 개수(len) 를 구하는 리스트를 만들라.
# 결과를 리스트로 출력하라.
# 예상 출력 예시:
# [6, 6, 6, 9]

words = ["python", "map", "filter", "lambda", "hi", "education", "code"]
filtered = filter(lambda word : len(word)>=5, words)
mapped = map(lambda word: len(word), filtered)
print(list(mapped))



# 3. 문제 3: 학생 점수 중 60점 이상만 통과 처리 + 보정점수 계산
# 학생 점수 리스트가 다음과 같다.
# scores = [35, 78, 92, 55, 61, 47, 88, 73]
# 조건
# filter로 60점 이상(합격) 점수만 걸러라.
# map으로 걸러진 점수에 +5점 보정 점수를 적용하라.
# 보정된 점수 리스트를 출력하라.
# 예상 출력 형태:
# [83, 97, 66, 93, 78]

scores = [35, 78, 92, 55, 61, 47, 88, 73]
filtered = filter(lambda score : score >=60, scores)
mapped = map(lambda word: word+5, filtered)
print(list(mapped))