import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000)

def findSection(r, c) :
    global area
    if r < 0 or r >= N or c < 0 or c >= N or table[r][c] == 0 : return area

    table[r][c] = 0
    area += 1

    findSection(r-1, c) # 위로 이동
    findSection(r+1, c) # 아래로 이동
    findSection(r, c-1) # 왼쪽으로 이동 
    findSection(r, c+1) # 오른쪽으로 이동

    return area

N = int(input())

table = []
estate = [] # 단지

for _ in range(N) :
    data = input().rstrip()
    line = []
    for l in data :
        line.append(int(l))

    table.append(line)

for r in range(N) :
    for c in range(N) :
        if table[r][c] == 1 :
            area = 0
            findSection(r, c)

            estate.append(area)

estate.sort()
print(len(estate))
for e in estate : print(e)