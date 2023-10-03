import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(V, E, R) : # V : 정점 집합, E : 간선 집합, R : 시작 정점
    global order
    vertex[R] = order
    visited[R] = True
    for x in sorted(list(E[R])) :
        if not visited[x[0]] :
            order += 1
            dfs(V, E, x[0])

N, M, R = map(int, input().split())

# 정점 집합
order = 1
vertex = [0 for _ in range(N+1)]
# 정점 집합
visited = [False for _ in range(N+1)]
# 간선 집합
enter = {
    # E(V) = {(x, e), (...), ... } # x : 종점, e : 가중치
}
for k in range(1, N+1) : enter[k] = set()

for _ in range(M) :
    u, v = map(int, input().split())
    enter[u].add((v, 1))
    enter[v].add((u, 1)) # 무방향 그래프, 양방향 대칭

dfs(vertex, enter, R)

for v in vertex[1:] : print(v)