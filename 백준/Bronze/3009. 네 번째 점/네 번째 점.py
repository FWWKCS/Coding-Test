x = []
y = []

for _ in range(3) :
    data = input().split()
    x.append(int(data[0]))
    y.append(int(data[1]))

x.sort()
y.sort()

if x.count(x[0]) == 1 : print(x[0], end = ' ')
else : print(x[2], end = ' ')

if y.count(y[0]) == 1 : print(y[0])
else : print(y[2])