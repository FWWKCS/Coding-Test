import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    flag = False
    N, M, W = map(int, input().split())
    edges = []
    for _ in range(M):
        S, E, T = map(int, input().split())
        edges.append((S, E, T))
        edges.append((E, S, T))
    
    for _ in range(W):
        S, E, T = map(int, input().split())
        edges.append((S, E, -T))

    dist = [int(10e9) for _ in range(N+1)]
    dist[1] = 0
    # Bellman-Ford

    for i in range(1, N+1):
        for s, e, w in edges:
            if dist[s]+w < dist[e]:
                if i == N: flag = True # cycled
                dist[e] = dist[s] + w

    if flag: print('YES')
    else: print('NO')      