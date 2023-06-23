count = int(input())
list = []
for i in range(count):
    num = input().split()
    a = int(num[0])
    b = int(num[1])
    list.append([a,b])
for i in range(count):
    print(f'Case #{i+1}: {list[i][0]} + {list[i][1]} = {list[i][0]+list[i][1]}')