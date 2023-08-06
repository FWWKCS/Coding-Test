import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000)

def findSection(r, c) :
    global area
    if r < 0 or r >= M or c < 0 or c >= N or table[r][c] == 1 : return 

    table[r][c] = 1
    area += 1

    findSection(r-1, c) # 위로 이동
    findSection(r+1, c) # 아래로 이동
    findSection(r, c-1) # 왼쪽으로 이동 
    findSection(r, c+1) # 오른쪽으로 이동



M, N, K = map(int, input().split())

table = [[0 for _ in range(N)] for _ in range(M)]
sections = [] # 분리된 각 면적의 넓이

for _ in range(K) :
    x0, y0, x1, y1 = map(int, input().split())
    
    for y in range(M-y1, M-y0) :
        for x in range(x0, x1) :
            table[y][x] = 1

for r in range(M) :
    for c in range(N) :
        if table[r][c] != 1 :
            area = 0 # 넓이
            findSection(r, c)

            sections.append(area)

sections.sort()

print(len(sections))
for s in sections : print(s, end = ' ')
