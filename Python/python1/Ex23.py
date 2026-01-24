
array=["사과", "자도", "초콜릿", "바나나", "체리"]
#output = [fruit for fruit in array if fruit !="초콜릿"]

#값으로 인덱스를 찾은 뒤 del로 삭제

#del array[array.index("초콜릿")] #이렇케는 사용 안하는것 같아.
array.remove("초콜릿")
print(array)
