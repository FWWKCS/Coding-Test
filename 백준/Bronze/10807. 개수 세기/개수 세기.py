count = int(input())
numList = input().split()
find = int(input())

countFind = 0
for i in numList:
    if int(i) == find : countFind += 1
print(countFind)