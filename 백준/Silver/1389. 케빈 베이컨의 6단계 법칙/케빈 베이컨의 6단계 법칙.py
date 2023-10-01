import collections
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [[-1 for _ in range(N)] for _ in range(N)]
for d in range(N) : # 대각영역은 자기자신(0)
    graph[d][d] = 0

for _ in range(M) :
    start, end = map(int, input().split())
    graph[start-1][end-1] = 1
    graph[end-1][start-1] = 1

# 각 노드의 인접단계 탐색
for k in range(N) :
    if -1 in graph[k] : # 아직 탐색되지않은 부분이 있으면
        # 그래프 깊이우선 탐색
        main = k+1
        depth = 0 # 단계
        visited = set() # 방문한 노드, 자신부터 시작
        queue = collections.deque([(main, depth)]) 
        while queue :
            current, depth = queue.popleft()
            visited.add(current)

            # 그래프 채우기
            if graph[k][current-1] == -1 : 
                graph[k][current-1] = depth
                graph[current-1][k] = depth

            # 그래프를 다 채운 후 모두 방문하면 종료
            if len(visited) == N : break

            target = -1
            for i in range(N) :
                if graph[current-1][i] == 1 and i+1 not in visited : # 방문하지 않은 곳이면
                    target = i # 다음 시작점으로 지정
                    queue.append((target+1, depth+1))

low_bacon_node = 0 # 출력할 노드
low_bacon = sys.maxsize

for g in range(N) :
    if sum(graph[g]) < low_bacon :
        low_bacon = sum(graph[g])
        low_bacon_node = g+1

print(low_bacon_node)