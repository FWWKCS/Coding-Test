import sys
input = sys.stdin.readline

V, E = map(int, input().split())

graph = [[float('inf') for _ in range(V+1)] for _ in range(V+1)]
distance = float('inf')

for _ in range(E):
    a, b, c = map(int, input().split())
    graph[a][b] = c

for k in range(1, V+1):
    for s in range(1, V+1):
        for e in range(1, V+1):
            graph[s][e] = min(graph[s][e], graph[s][k]+graph[k][e])
            if s == e: distance = min(distance, graph[s][e])

if distance == float('inf'): print(-1)
else: print(distance)