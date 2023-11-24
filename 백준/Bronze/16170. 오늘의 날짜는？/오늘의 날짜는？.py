import datetime as dt

now = dt.datetime.now() - dt.timedelta(hours=9)

print(now.year)
print(now.month)
print(now.day)