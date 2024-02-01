import sys
input = sys.stdin.readline

def dfs(prev, current):
    visited.add(current)
    for v in graph[current]:
        if v == prev: continue
        # 이동할 수 있는 정점이 이미 방문되어있으면 사이클
        if v in visited: return False
        if not dfs(current, v): return False
    
    return True

case_count = 1
while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0: break

    graph = {
        # 시작 정점 : { 출발 정점 }
    }
    for i in range(1, n+1): graph[i] = []
    for _ in range(m): 
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    
    visited = set()
    T = 0
    for k in range(1, n+1):
        if k in visited: continue

        if dfs(-1, k): T += 1

    if T == 0: print(f'Case {case_count}: No trees.')
    elif T == 1: print(f'Case {case_count}: There is one tree.')
    else: print(f'Case {case_count}: A forest of {T} trees.')
    case_count += 1