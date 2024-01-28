from heapq import heappush, heappop
import sys
input = sys.stdin.readline

def dijkstra(s, dist, trace, graph):
    heap = [(0, s)] # [ (출발 노드, 현재 거리)]
    visited = set()
    while heap:
        weight, current = heappop(heap)
        visited.add(current)
        if current not in graph: continue

        for e, k in list(graph[current]):
            if e not in visited and weight + k < dist[e]:
                heappush(heap, (weight+k, e))
                dist[e] = weight + k
                trace[e] = current

N = int(input())
M = int(input())
graph = {
    # 시작: { (도착, 가중치), ... }
}

for _ in range(M):
    s, e, w = map(int, input().split())
    if s not in graph:
        graph[s] = {(e, w)}
    else:
        graph[s].add((e, w))

s, e = map(int, input().split())

dist = [int(10e9) for _ in range(N+1)]
trace = [-1 for _ in range(N+1)]
dist[s] = 0

dijkstra(s, dist, trace, graph)

print(dist[e])
route = [e]
current = e
while current != s:
    route.append(trace[current])
    current = route[-1]

print(len(route))
for i in range(len(route)-1, -1, -1):
    print(route[i], end = ' ')