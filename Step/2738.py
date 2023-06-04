# https://www.acmicpc.net/problem/2738

ArrSize = input().split()

row = int(ArrSize[0])
col = int(ArrSize[1])

opA = []
opB = []

for _ in range(row):
    opA.append(list(map(int, input().split())))
   
for _ in range(row):
    opB.append(list(map(int, input().split())))
    
for r in range(row):
    for c in range(col):
        print(opA[r][c]+opB[r][c], end=" ")
    print()