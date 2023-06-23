list = []

a = b = 1

while(True):
    num = input().split()
    a = int(num[0])
    b = int(num[1])
    if (a == 0 and b == 0) : break
    list.append(a+b)

for i in range(len(list)): print(list[i])
    