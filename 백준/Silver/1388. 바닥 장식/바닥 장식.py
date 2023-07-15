import sys
input = sys.stdin.readline

ROW, COL = map(int, input().split())

# 바닥형태를 2차원 배열로 기록
floor = [] 
for _ in range(ROW) :
    floor.append(list(input().rstrip()))

count = 0 # 개수 연산

for r in range(ROW) : # 행
    for c in range(COL) : # 열
        if floor[r][c] == 'X' : continue

        y = r
        x = c
        if floor[y][x] == '-' :
            while x != COL :
                if floor[y][x] in ('|', 'X') : break

                floor[y][x] = 'X'
                x += 1
            
            count += 1

        elif floor[y][x] == '|' :
            while y != ROW :
                if floor[y][x] in ('-', 'X') : break

                floor[y][x] = 'X'
                y += 1
            
            count += 1

print(count)
        