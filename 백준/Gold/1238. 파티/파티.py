from heapq import heappush, heappop
import sys
input = sys.stdin.readline

def dijkstra(X, dist):
    heap = [(0, X)]
    visited = set()
    while heap:
        _, s = heappop(heap)
        visited.add(s)
        if s not in graph: continue

        for e, w in graph[s]:
            if e not in visited and dist[s] + w < dist[e]:
                dist[e] = dist[s] + w
                heappush(heap, (dist[e], e))


N, M, X = map(int, input().split())
graph = {
    # 출발 : [(도착, 가중치), ... ]
}
for _ in range(M):
    s, e, w = map(int, input().split())
    if s not in graph:
        graph[s] = [(e, w)]
    else: graph[s].append((e, w))

total = [0 for _ in range(N+1)]

min_dist = [[float('inf') for _ in range(N+1)]]

for i in range(1, N+1):
    dist = [float('inf') for _ in range(N+1)]
    dist[i] = 0
    dijkstra(i, dist)
    min_dist.append(dist)

for i in range(1, N+1):
    total[i] += min_dist[i][X] + min_dist[X][i]

print(max(total))