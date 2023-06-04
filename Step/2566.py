# https://www.acmicpc.net/problem/2566

# 9 X 9 배열의 최댓값 탐색

row = 9

table = []

for _ in range(row):
    table.append(list(map(int, input().split())))

rowIndex, colIndex, maxValue = 0, 0, 0

for r in range(row):
    if maxValue < max(table[r]) : 
        maxValue = max(table[r])
        rowIndex = r
        colIndex = table[r].index(maxValue)

print(maxValue)
print(rowIndex+1, colIndex+1)