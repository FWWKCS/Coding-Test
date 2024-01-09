from collections import deque
import sys
input = sys.stdin.readline

def bfs(R):
    global graph, visit, count
    visited = {R}
    queue = deque([(R, count)])

    while queue:
        R, C = queue.popleft()
        visit[R] = C
        if R not in graph: continue

        for target in graph[R]:
            if target not in visited:
                count += 1
                visited.add(target)
                queue.append((target, count))

N, M, R = map(int, input().split())
graph = {
    # 시작 정점: [인접 정점]
}
visit = [0 for _ in range(N+1)]
count = 1

for _ in range(M):
    u, v = map(int, input().split())
    if u not in graph:
        graph[u] = [v]
    else:
        graph[u].append(v)
    
    if v not in graph:
        graph[v] = [u]
    else:
        graph[v].append(u)

for x in graph.keys():
    graph[x].sort() # 오름차순 정렬

bfs(R)
for i in range(1, N+1):
    print(visit[i])