from collections import deque
import sys
input = sys.stdin.readline

case_count = 1
while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0: break

    graph = { 
        # 시작 정점 : { 도착 정점 }
    }
    for i in range(1,n+1): graph[i] = set()
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].add(b)
        graph[b].add(a)

    processed = set()
    T = 0
    for x in range(1, n+1):
        if x in processed: continue

        visited = set()
        E = 0 # 형태를 이루는 간선 개수
        queue = deque([x])
        while queue:
            current = queue.popleft()
            visited.add(current)
            processed.add(current)
            E += len(graph[current])

            for k in list(graph[current]):
                if k not in visited:
                    queue.append(k)

        if len(visited) - (E//2) == 1: T += 1

    if T == 0:
        print(f'Case {case_count}: No trees.')
    elif T == 1:
        print(f'Case {case_count}: There is one tree.')
    else:
        print(f'Case {case_count}: A forest of {T} trees.')

    case_count += 1      