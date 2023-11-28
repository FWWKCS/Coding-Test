import sys
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [[float("inf") for _ in range(N)] for _ in range(N)]
for d in range(N) : # 대각영역은 자기자신(0)
    graph[d][d] = 0

for _ in range(M) :
    start, end = map(int, input().split())
    graph[start-1][end-1] = 1
    graph[end-1][start-1] = 1

# 각 노드의 인접단계 탐색
# 플로이드 워셜 알고리즘
for k in range(N) :
    # r에서 c로 이동하면서, k+1 노드를 거쳐가거나 다이렉트로 갈 수 있을때의 최단거리
    for r in range(N) :
        if r == k : continue
        for c in range(N) : 
            if r == c or c == k : continue

            graph[r][c] = min(graph[r][c], graph[r][k] + graph[k][c])

low_bacon_node = 0 # 출력할 노드
low_bacon = float("inf")

for g in range(N) :
    if sum(graph[g]) < low_bacon :
        low_bacon = sum(graph[g])
        low_bacon_node = g+1

print(low_bacon_node)