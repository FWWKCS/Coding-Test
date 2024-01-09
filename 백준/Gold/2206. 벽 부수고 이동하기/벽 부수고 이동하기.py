from collections import deque
import sys
input = sys.stdin.readline

def bfs():
    global length, found
    visited[0][1][1] = True
    visited[1][1][1] = True
    queue = deque([(0, 1, 1, 1)]) # (dim, r, c, distance)

    while queue:
        dim, r, c, distance = queue.popleft()
        if r == N and c == M: 
            found = True
            length = min(length, distance)
            continue
        
        for dr, dc in list(zip(pr, pc)):
            tr = r+dr # target_row
            tc = c+dc # target_col
            if 1 <= tr and tr <= N and 1 <= tc and tc <= M:
                # 아직 벽을 마주하지 않은 경우(dim = 0)
                if dim == 0 and not visited[dim][tr][tc]:
                    # 1인 경우 벽돌을 부순 경우로 변경
                    if table[dim][tr][tc] == 1:
                        visited[0][tr][tc] = True
                        visited[1][tr][tc] = True
                        queue.append((1, tr, tc, distance+1))
                        continue
                    # 0인 경우 그대로 진행
                    else:
                        visited[0][tr][tc] = True
                        queue.append((0, tr, tc, distance+1))
                # 벽을 이미 마주한 경우 (dim = 1)
                elif dim == 1 and not visited[dim][tr][tc]:
                    # 1인 경우 더이상 갈 수 없다
                    if table[dim][tr][tc] == 1:
                        continue    
                    # 0인 경우 그대로 진행
                    else:
                        visited[1][tr][tc] = True
                        queue.append((dim, tr, tc, distance+1))

N, M = map(int, input().split())
table = [[[0 for _ in range(M+1)]] + [[0] + list(map(int, list(input().rstrip()))) for _ in range(N)]] * 2
visited = [[[False for _ in range(M+1)] for _ in range(N+1)] for _ in range(2)]

pr = [-1, 1, 0, 0]
pc = [0, 0, -1, 1]
# up, down, left, right

length = float('inf')
found = False

bfs()

if found: print(length)
else: print(-1)