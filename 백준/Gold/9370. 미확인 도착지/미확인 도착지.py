from heapq import heappush, heappop
import sys
input = sys.stdin.readline

def dijkstra(start, except_v):
    global graph

    distance = [int(1e9) for _ in range(n+1)]
    distance[start] = 0

    visited = set()
    heap = [(0, start)]

    while heap:
        weight, pos = heappop(heap)
        visited.add(pos)
        if pos not in graph: continue
    
        for target, length in list(graph[pos]):
            if target not in visited and weight+length < distance[target] and target not in except_v:
                    distance[target] = weight+length
                    heappush(heap, (distance[target], target))
    
    return distance

T = int(input())
for _ in range(T):
    n, m, t = map(int, input().split())
    s, g, h = map(int, input().split())
    graph = {
        # a: {(b, d), ... }
    }
    
    # make graph
    for _ in range(m):
        a, b, d = map(int, input().split())
        if a not in graph:
            graph[a] = {(b, d)}
        else: graph[a].add((b, d))

        if b not in graph:
            graph[b] = {(a, d)}
        else: graph[b].add((a, d))

    predict = [int(input()) for _ in range(t)]
    possible = []

    # 교차로 무관 최소거리 계산
    origin = dijkstra(s, set()) 

    # 교차로를 거쳤을 때 받은 최단거리와 같으면 가능한 목적지
    # case 1) s -> g -> h -> 후보 정점
    # case 2) s -> h -> g -> 후보 정점

    # s -> g 최단 거리 배열 
    A1 = dijkstra(s, set())

    # s -> h 최단 거리 배열
    A2 = dijkstra(s, set())

    # g -> h ( h -> g ) 최단 거리 배열
    B = dijkstra(g, set())

    # h -> 후보 정점
    C1 = dijkstra(h, {s, g})

    # g -> 후보 정점
    C2 = dijkstra(g, {s, h})

    for p in predict:
        case1 = A1[g] + B[h] + C1[p]
        case2 = A2[h] + B[h] + C2[p]
        
        if origin[p] == min(case1, case2):
            possible.append(p)
    
    print(*sorted(possible))