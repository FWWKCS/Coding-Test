from heapq import heappush, heappop
import sys
input = sys.stdin.readline

V, E = map(int, input().split())
K = int(input())

graph = {
    # u: (v, w), (...)
}

for _ in range(E):
    u, v, w = map(int, input().split())

    if u not in graph:
        graph[u] = {(v,w)}
    else:
        graph[u].add((v,w))

distance = [float('inf') for _ in range(V+1)]
distance[K] = 0
heap = []
heappush(heap, (0, K)) # 출발점

visited = set()

while heap:
    weight, vertex = heappop(heap)
    # 최소 거리를 가지는 정점 추출
    
    visited.add(vertex)
    if vertex not in graph: continue

    # 인접 방향 정점까지의 가중치 최소값을 갱신
    for v, w in list(graph[vertex]):
        if v not in visited:
            if distance[v] > weight+w:
                distance[v] = weight+w
                heappush(heap, (distance[v], v))

for i in range(1, V+1): 
    if distance[i] == float('inf'): print('INF')
    else: print(distance[i])