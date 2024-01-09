from heapq import heappush, heappop
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)

N, M, R = map(int, input().split())
graph = {
    # 출발 정점 : {인접한 정점}
}
visit = [0 for _ in range(N+1)] # 방문 순서
count = 1

visited = set()
for _ in range(M):
    u, v = map(int, input().split())
    if u not in graph:
        graph[u] = [-v]
    else:
        heappush(graph[u], -v)

    if v not in graph:
        graph[v] = [-u]
    else:
        heappush(graph[v], -u)

def dfs(R):
    global graph, count
    visited.add(R)
    visit[R] = count
    if R not in graph: return

    for _ in range(len(graph[R])):
        target = -heappop(graph[R])
        if target not in visited:
            count += 1
            dfs(target)

dfs(R)
for i in range(1, N+1):
    print(visit[i])