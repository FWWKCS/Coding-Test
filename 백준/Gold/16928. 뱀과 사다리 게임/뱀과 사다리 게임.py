import collections

N, M = map(int, input().split())
trigger = {
    # 시점: 종점
}

for _ in range(N+M):
    start, end = map(int, input().split())
    trigger[start] = end

visited = [False for _ in range(101)]
visited[1] = True # 시작점

count = float('inf')
queue = collections.deque([(1,0)])
while queue:
    pos, rolled = queue.popleft()

    if pos >= 100:
        count = min(count, rolled)
        continue

    for i in range(1, 7):
        if pos+i < 100 and not visited[pos+i]:
            if pos+i in trigger:
                queue.append((min(100, trigger[pos+i]), rolled+1))
            else: queue.append((min(100, pos+i), rolled+1))
            visited[pos+i] = True 
        elif pos+i >= 100:
            queue.append((100, rolled+1))
            visited[100] = True
    
print(count)