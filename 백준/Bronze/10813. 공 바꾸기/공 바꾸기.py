data = input().split()
basketRange = int(data[0])
count = int(data[1])

basket = list(range(1,basketRange+1))

for i in range(count):
    change = input().split()
    a = int(change[0])
    b = int(change[1])
    if a != b :
        tmp = basket[a-1]
        basket[a-1] = basket[b-1]
        basket[b-1] = tmp
    else : continue

for i in basket : print(i, end = ' ')