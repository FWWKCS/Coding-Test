import collections
import sys
input = sys.stdin.readline

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]

def bfs(i) :
    queue = collections.deque([])
    visited = set()
    current = i

    # current와 연결된 지점을 queue에 대입
    for t in range(N) :
        if graph[i][t] == 1 :
            queue.append(t+1)
    
    # bfs
    while queue :
        current = queue.popleft()-1
        visited.add(current+1)

        if graph[i][current] == 0 : graph[i][current] = 1

        for j in range(N) :
            if graph[current][j] == 1 and j+1 not in visited :
                queue.append(j+1)

# 출발점은 i일때
for i in range(N) : bfs(i)

# 최종 경로표 출력
for t in graph : print(*t)