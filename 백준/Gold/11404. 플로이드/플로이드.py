import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
graph = [[float('inf') for _ in range(n+1)] for _ in range(n+1)]

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a][b] = min(graph[a][b], c)

# 플로이드-워셜 알고리즘
for x in range(1, n+1):
    # x를 중간으로 하는 최단 경로
    # D_ab = min(D_ab, D_ax+D_xb) 
    for r in range(1, n+1):
        if r == x: continue
        for c in range(1, n+1):
            if c == x: continue
            
            if r == c: 
                graph[r][c] = 0
                continue

            graph[r][c] = min(graph[r][c], graph[r][x]+graph[x][c])

for r in range(1, n+1):
    for c in range(1, n+1):
        if graph[r][c] == float('inf'): 
            graph[r][c] = 0
        print(graph[r][c], end=' ')
    print()