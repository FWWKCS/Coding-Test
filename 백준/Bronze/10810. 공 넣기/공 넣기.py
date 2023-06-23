data = input().split()
setRange = int(data[0])
count = int(data[1])

basket = []
for i in range(setRange): basket.append(0)

for i in range(count) :
    method = input().split()
    a = int(method[0])
    b = int(method[1])
    ballNum = int(method[2])

    for j in range(a,b+1):
        basket[j-1] = ballNum

for i in range(len(basket)) : print(basket[i], end = ' ')