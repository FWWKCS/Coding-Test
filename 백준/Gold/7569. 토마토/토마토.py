import collections
import sys
input = sys.stdin.readline

def check_tomatoes(days):
    for h in range(H) :
        for r in range(N) :
            for c in range(M) :
                if box[h][r][c] == 0 :
                    return -1
    
    return days


def bfs() :
    global box, visited

    queue = collections.deque([])
    for h in range(H) :
        for r in range(N) :
            for c in range(M) :
                if box[h][r][c] == 1 :
                    queue.append((0, c, r, h))
                    visited[h][r][c] = True

    days = 0
    while queue:
        days, x, y, z = queue.popleft()
        box[z][y][x] = 1

        # 위 이동
        if z < H-1 and not visited[z+1][y][x] and box[z+1][y][x] == 0 :
            queue.append((days+1, x, y, z+1))
            visited[z+1][y][x] = True
        # 아래 이동
        if z > 0 and not visited[z-1][y][x] and box[z-1][y][x] == 0 :
            queue.append((days+1, x, y, z-1))
            visited[z-1][y][x] = True
        # 앞 이동
        if y > 0 and not visited[z][y-1][x] and box[z][y-1][x] == 0 :
            queue.append((days+1, x, y-1, z))
            visited[z][y-1][x] = True
        # 뒤 이동
        if y < N-1 and not visited[z][y+1][x] and box[z][y+1][x] == 0 :
            queue.append((days+1, x, y+1, z))
            visited[z][y+1][x] = True
        # 왼쪽 이동
        if x > 0 and not visited[z][y][x-1] and box[z][y][x-1] == 0 :
            queue.append((days+1, x-1, y, z))
            visited[z][y][x-1] = True
        # 오른쪽 이동
        if x < M-1 and not visited[z][y][x+1] and box[z][y][x+1] == 0:
            queue.append((days+1, x+1, y, z))
            visited[z][y][x+1] = True

    return days


M, N, H = map(int, input().split())

box = []
visited = []
for _ in range(H) :
    box.append([list(map(int, input().split())) for _ in range(N)])
    visited.append([[False for _ in range(M)] for _ in range(N)])

days = bfs()

# 익지않은 토마토 확인
print(check_tomatoes(days))