x = []
y = []

count = int(input())
for r in range(count) :
    data = input().split()
    x.append(int(data[0]))
    y.append(int(data[1]))


x = list(set(x))
y = list(set(y))
x.sort()
y.sort()

xMax = x.pop()
yMax = y.pop()

if len(x) == 0 : xMin = xMax
else : xMin = x[0]

if len(y) == 0 : yMin = yMax
else : yMin = y[0]

print((xMax-xMin)*(yMax-yMin))