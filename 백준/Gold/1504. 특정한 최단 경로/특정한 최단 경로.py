from heapq import heappush, heappop
import sys
input = sys.stdin.readline

N, E = map(int, input().split())
graph = {
    # u: (v, w), ...
}
for _ in range(E):
    a, b, c = map(int, input().split())
    if a not in graph:
        graph[a] = {(b, c)}
    else:
        graph[a].add((b, c))

    if b not in graph:
        graph[b] = {(a, c)}
    else:
        graph[b].add((a, c))

v1, v2 = map(int, input().split())

def dijkstra(v1, v2):
    global graph

    if v1 < v2:
        a = v1
        b = v2
    else: # v1 > v2
        a = v2
        b = v1

    distance = [float('inf') for _ in range(N+1)]
    distance[v1] = 0

    visited = set()
    heap = [(0, v1)]

    while heap:
        weight, pos = heappop(heap)
        if pos not in graph: continue
        
        for target, k in list(graph[pos]):
            if target not in visited:
                if weight+k < distance[target]:
                    distance[target] = weight+k
                    heappush(heap, (distance[target], target))

    return distance[v2]


# case 1. 1 -> v1 -> v2 -> N
# case 2. 1 -> v2 -> v1 -> N

# 1 -> v1
A1 = dijkstra(1, v1)

# 1 -> v2
A2 = dijkstra(1, v2)

# v1 -> v2
B = dijkstra(v1, v2)

# v1 -> N
C1 = dijkstra(v1, N)

# v2 -> N
C2 = dijkstra(v2, N)

case1 = A1+B+C2
case2 = A2+B+C1

if min(case1, case2) == float('inf'):
    print(-1)
else: print(min(case1, case2))