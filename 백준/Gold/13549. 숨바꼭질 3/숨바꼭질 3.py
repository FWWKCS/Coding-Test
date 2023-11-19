from collections import deque

N, K = map(int, input().split())

def bfs(current, end):
    global visited
    queue = deque([(current, 0)])

    while queue:
        pos, t = queue.popleft()
        if pos == end:
            visited[pos] = min(visited[pos], t)
            continue
        elif pos > end:
            visited[end] = min(visited[end], t+pos-end)
            continue

        # 2*X
        if 2*pos < 100001 and t < visited[2*pos]:
            visited[2*pos] = t
            queue.append((pos*2, t))

        # X+1
        if pos+1 != 100001 and t+1 < visited[pos+1]:
            visited[pos+1] = t+1
            queue.append((pos+1, t+1))
        
        # X-1
        if pos-1 != -1 and t+1 < visited[pos-1]:
            visited[pos-1] = t+1
            queue.append((pos-1, t+1))
        
visited = [float('inf') for _ in range(100001)]
visited[N] = 0
bfs(N, K)

print(visited[K])