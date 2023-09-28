import collections
import sys
input = sys.stdin.readline

def bfs(x, y) : # x : col, y : row
    depth = 0
    redraw[y][x] = 0 # 시작점은 0
    queue = collections.deque([(depth, x, y)])
    
    while queue :
        current = queue.popleft()
        depth = current[0]
        x = current[1]
        y = current[2]

        # 배열 거리 연산
        if table[y][x] == 1 : redraw[y][x] = depth

        # 위로 이동
        if y > 0 and redraw[y-1][x] == -1 and table[y-1][x] != 0 and not visited[y-1][x] :
            visited[y-1][x] = True
            queue.append((depth+1, x, y-1))
        # 아래로 이동
        if y < n-1 and redraw[y+1][x] == -1 and table[y+1][x] != 0 and not visited[y+1][x] :
            visited[y+1][x] = True
            queue.append((depth+1, x, y+1))
        # 왼쪽으로 이동
        if x > 0 and redraw[y][x-1] == -1 and table[y][x-1] != 0 and not visited[y][x-1] :
            visited[y][x-1] = True
            queue.append((depth+1, x-1, y))
        # 오른쪽으로 이동
        if x < m-1 and redraw[y][x+1] == -1 and table[y][x+1] != 0 and not visited[y][x+1] :
            visited[y][x+1] = True
            queue.append((depth+1, x+1, y))

    # 완성된 table 출력 및 종료
    for r in redraw : print(*r)
    sys.exit()

n, m = map(int, input().split())
table = [list(map(int, input().split())) for _ in range(n)]
visited = [[False for _ in range(m)] for _ in range(n)] # 방문 리스트
redraw = [[-1 for _ in range(m)] for _ in range(n)]

start_x, start_y = 0, 0
for r in range(n) :
    for c in range(m) :
        if table[r][c] == 0 : redraw[r][c] = 0
        if table[r][c] == 2 : 
            start_x, start_y = c, r
            visited[r][c] = True

bfs(start_x, start_y)