
import random

print(" - random():", random.random())
print(" - uniform(10,20)", random.uniform(10,20))
print(" - uniform(10,20)", int(random.uniform(10,20)))
print(" - randange(10,2)", random.randrange(10, 20))
print(" - choice([1,2,3,4,5])", random.choice([1,2,3,4,5]))
alist=[1,2,3,4,5]
random.shuffle(alist)
print(" - shuffle([1,2,3,4,5])", alist)

blist=[1,2,3,4,5,6,7,8,9]
print(random.sample(blist, k=2 ))

