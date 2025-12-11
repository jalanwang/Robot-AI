# 1
# import urllib.request

# 2
# from urllib import request

# 3
from urllib.request import urlopen

#1
# target = urllib.request.urlopen("https://google.com/").read()
#2
# target = request.urlopen("https://google.com/").read()
#3
target = urlopen("https://google.com/").read()

# 파이로 저장해서 웹서버로 열어보자.