import datetime

now=datetime.datetime.now()

month=now.month

if month>1 and month<4:
    print("Spring")
elif month>=4 and month<8:
    print("Summer")
elif month>=9 and month<11:
    print("Autumn")
else:
    print("Winter")

