from collections import deque
import sys
input = sys.stdin.readline

def bfs():
    global graph
    used = set() # 사용된 정점, 서로 연결된 부분 그래프 단위로 기록
    for k in graph.keys():
        if k in used: continue

        sector_A = {k}
        sector_B = set()
        queue = deque([k])
        visited = {k}

        while queue:
            current = queue.popleft()
            if current not in graph: continue

            # current 값이 없는 집합에 인접 집합을 합 연산
            if current not in sector_A:
                sector_A |= graph[current]
            elif current not in sector_B:
                sector_B |= graph[current]
            else: # 양쪽에 정점이 모두 존재하는 경우
                return False
            
            for x in list(graph[current]):
                if x not in visited:
                    visited.add(x)
                    queue.append(x)
            
        if len(sector_A & sector_B) == 0: 
            used |= (sector_A | sector_B)
            pass
        else: return False

    return True

T = int(input())
for _ in range(T):
    graph = {
        # 시작 정점: {인접 정점 집합}
    }
    V, E = map(int, input().split())
    if V > 2 and E == 1: 
        print('YES')
        continue
    elif E == 1:
        print('NO')
        continue

    for _ in range(E):
        u, v = map(int, input().split())
        if u not in graph:
            graph[u] = {v}
        else:
            graph[u].add(v)

        if v not in graph:
            graph[v] = {u}
        else:
            graph[v].add(u)
    
    splited = bfs()
    if splited: print('YES')
    else: print('NO')