import sys
input = sys.stdin.readline

N, M = map(int, input().split())
paper = [list(map(int, input().split())) for _ in range(N)]

total = 0 # 합의 최댓값

# 가로 3칸 + Right, Up, Down, Center(Up, Down), Back(Up, Down) 블럭 하나의 합
for r in range(N):
    tmp = sum(paper[r][:3])
    for c in range(2, M):
        if c >= 3:
            tmp -= paper[r][c-3]
            tmp += paper[r][c]
        # add in Right
        if c+1 != M: 
            total = max(total, tmp+paper[r][c+1])
        # add in Up, Center Up, Back Up
        if r-1 >= 0 and c-2 >= 0 and c-1 >= 0: 
            total = max(total, tmp+paper[r-1][c], tmp+paper[r-1][c-1], tmp+paper[r-1][c-2])
        # add in Down, Center Down, Back Down
        if r+1 != N and c-2 >= 0 and c-1 >= 0:
            total = max(total, tmp+paper[r+1][c], tmp+paper[r+1][c-1], tmp+paper[r+1][c-2])
        
# 세로 3칸 + Left, Right, Down, Center(Left, Right), Back(Left, Right) 블럭 하나의 합
for r in range(2, N):
    tmp = paper[r-2][0] + paper[r-1][0] + paper[r][0]
    for c in range(M):
        if c >= 1:
            tmp -= paper[r-2][c-1] + paper[r-1][c-1] + paper[r][c-1]
            tmp += paper[r-2][c] + paper[r-1][c] + paper[r][c]
        # add in Down
        if r+1 != N: total = max(total, tmp+paper[r+1][c])
        # add in Left, Center Left, Back Left
        if r-2 >= 0 and r-1 >= 0 and c-1 >= 0:
            total = max(total, tmp+paper[r][c-1], tmp+paper[r-1][c-1], tmp+paper[r-2][c-1])
        # add in Right, Center Right, Back Right
        if r-1 >= 0 and r-2 >= 0 and c+1 != M:
            total = max(total, tmp+paper[r][c+1], tmp+paper[r-1][c+1], tmp+paper[r-2][c+1])
    
# z블럭 검사
# 가로 2칸 + 양쪽 끝 연장 블럭 2개
for r in range(N):
    tmp = sum(paper[r][:2]) 
    for c in range(1, M):
        if c >= 2:
            tmp -= paper[r][c-2]
            tmp += paper[r][c]
        # add in Up Right
        if r-1 >= 0 and c+1 != M:
            total = max(total, tmp+paper[r-1][c]+paper[r-1][c+1])
        # add in Down Right
        if r+1 != N and c+1 != M:
            total = max(total, tmp+paper[r+1][c]+paper[r+1][c+1])
        # add in Up Left
        if r-1 >= 0 and c-2 >= 0 and c-1 >= 0:
            total = max(total, tmp+paper[r-1][c-1]+paper[r-1][c-2])
        # add in Down Left
        if r+1 != N and c-2 >= 0 and c-1 >= 0:
            total = max(total, tmp+paper[r+1][c-1]+paper[r+1][c-2])

# 세로 2칸 + 양쪽 끝 연장 블럭 2개
for r in range(1, N):
    tmp = paper[r-1][0] + paper[r][0]
    for c in range(M):
        if c >= 1:
            tmp -= paper[r-1][c-1] + paper[r][c-1]
            tmp += paper[r-1][c] + paper[r][c]
        # add in Right Down
        if r+1 != N and c+1 != M:
            total = max(total, tmp+paper[r][c+1]+paper[r+1][c+1])
        # add in Left Down
        if r+1 != N and c-1 >= 0:
            total = max(total, tmp+paper[r][c-1]+paper[r+1][c-1])
        # add in Right Up
        if r-2 >= 0 and r-1 >= 0 and c+1 != M:
            total = max(total, tmp+paper[r-1][c+1]+paper[r-2][c+1])
        # add in Left Up
        if r-1 >= 0 and r-2 >= 0 and c-1 >= 0:
            total = max(total, tmp+paper[r-1][c-1]+paper[r-2][c-1])

# 2x2 블럭 영역 검사
for r in range(1, N):
    for c in range(1, M):
        total = max(total, paper[r-1][c-1]+paper[r-1][c]+paper[r][c-1]+paper[r][c])

print(total)