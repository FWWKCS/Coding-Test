count = int(input())

data = []

for _ in range(count) :
    info = input().split()
    age = int(info[0])
    name = info[1]

    data.append((age,name))

data.sort(key = lambda x : x[0])

for d in data : 
    print(f"{d[0]} {d[1]}")