import copy
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000)

def findSection(table, r, c, is_colorWeakness, color) :
    if r < 0 or r >= N or c < 0 or c >= N or table[r][c] == 'X' : return
    
    if is_colorWeakness :
        if color in ('R','G') and table[r][c] == 'B' : return
        elif color == 'B' and table[r][c] in ('R','G') : return
    else :
        if color != table[r][c] : return

    table[r][c] = 'X'

    findSection(table, r-1, c, is_colorWeakness, color) # 위로 이동
    findSection(table, r+1, c, is_colorWeakness, color) # 아래로 이동
    findSection(table, r, c-1, is_colorWeakness, color) # 왼쪽으로 이동 
    findSection(table, r, c+1, is_colorWeakness, color) # 오른쪽으로 이동

N = int(input())

n_table = []

non_colorWeakness = 0
colorWeakness = 0

for _ in range(N) :
    data = input().rstrip()
    line = []
    for l in data :
        line.append(l)

    n_table.append(line)

c_table = copy.deepcopy(n_table) # table 깊은 복사


for r in range(N) :
    for c in range(N) :
        # 색약이 아닌 사람의 시점
        if n_table[r][c] != 'X' :
            findSection(n_table, r, c, False, n_table[r][c])
            non_colorWeakness += 1
        # 색약인 사람의 시점
        if c_table[r][c] != 'X' :
            findSection(c_table, r, c, True, c_table[r][c])
            colorWeakness += 1

print(non_colorWeakness, colorWeakness)
