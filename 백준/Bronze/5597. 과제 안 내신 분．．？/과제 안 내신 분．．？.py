absent = list(range(1,31))

for i in range(28):
    num = int(input())
    absent.remove(num)

for i in absent: print(i, end = ' ')