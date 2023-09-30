import collections
import sys
input = sys.stdin.readline

def bfs(R, C) :
    global encounter, N, M
    queue = collections.deque([(R, C)])

    while queue :
        y, x = queue.popleft()

        if board[y][x] == 'P' : encounter += 1

        # 위로 이동
        if y > 0 and not visited[y-1][x] and board[y-1][x] != 'X' :
            visited[y-1][x] = True
            queue.append((y-1, x))
        # 아래로 이동
        if y < N-1 and not visited[y+1][x] and board[y+1][x] != 'X' :
            visited[y+1][x] = True
            queue.append((y+1, x))
        # 왼쪽으로 이동
        if x > 0 and not visited[y][x-1] and board[y][x-1] != 'X' :
            visited[y][x-1] = True
            queue.append((y, x-1))
        # 오른쪽으로 이동
        if x < M-1 and not visited[y][x+1] and board[y][x+1] != 'X' :
            visited[y][x+1] = True
            queue.append((y, x+1))
    
N, M = map(int, input().split())
board = [list(input()) for _ in range(N)]
visited = [[False for _ in range(M)] for _ in range(N)]

# 도연 위치에서 시작
encounter = 0
found = False
for r in range(N) :
    for c in range(M) :
        if board[r][c] == 'I' :
            found = True
            visited[r][c] = True
            bfs(r,c)
            break
    if found : break

if encounter > 0 : print(encounter)
else : print('TT')