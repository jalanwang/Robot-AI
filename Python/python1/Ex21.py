#items() 사용
#튜플로 변경하는데 이걸 또 안하는 방법도 있어.
dic = {
    "key1": "value1",
    "key2": "value2",
    "key3": "value3"
}
# for key, value in dic.items():
#     print("{}".format(dic[key]))


#이런걸로도 사용 가능
#dic.keys()
#dic.values()

for key in dic: #튜플로 안하고 출력하기
    print("{}:{}".format(key, dic.get(key)))

# for key, value in dic.items():
#     print("{}:{}".format(key, value))