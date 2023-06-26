count = int(input())

data = []
tmp = []

for _ in range(count) :
    data.append(tuple(map(int,input().split())))

data.sort()

for p in data :
    print(f"{p[0]} {p[1]}")