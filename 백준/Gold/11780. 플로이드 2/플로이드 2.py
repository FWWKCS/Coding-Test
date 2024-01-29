from collections import deque
import sys
input = sys.stdin.readline

N = int(input())
M = int(input())
graph = [[0 for _ in range(N+1)]] + [[0] + [float('inf') for _ in range(N)] for _ in range(N)]
for x in range(1, N+1): graph[x][x] = 0

trace = [[-1 for _ in range(N+1)] for _ in range(N+1)]


def back_tracking(s, e, route):
    mid = trace[s][e]
    if mid == -1: 
        route.append(e)
        return
    
    back_tracking(s, mid, route)
    back_tracking(mid, e, route)


for _ in range(M):
    s, e, w = map(int, input().split())
    graph[s][e] = min(graph[s][e], w)

# Floyd-Warshall
for k in range(1, N+1):
    for r in range(1, N+1):
        for c in range(1, N+1):
            if r == c: continue

            if graph[r][k] + graph[k][c] < graph[r][c]:
                graph[r][c] = graph[r][k] + graph[k][c]
                trace[r][c] = k

impossible = deque([])
for r in range(1, N+1):
    for c in range(1, N+1):
        if graph[r][c] == float('inf'): 
            print(0, end = ' ')
            impossible.append((r, c))
            continue
        print(graph[r][c], end = ' ')
    
    print()

for r in range(1, N+1):
    for c in range(1, N+1):
        if r == c: 
            print(0)
            continue

        if impossible and (impossible[0][0] == r and impossible[0][1] == c):
            impossible.popleft()
            print(0)
            continue
        
        route = []
        back_tracking(r, c, route)
        print(len(route)+1, end = ' ')
        print(r, end = ' ')
        for i in route: print(i, end = ' ')
        print()