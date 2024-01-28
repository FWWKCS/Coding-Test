from collections import deque

N, K = map(int, input().split())

peak = 100001
time = [float('inf') for _ in range(100001)]
time[N] = 0

trace = [-1 for _ in range(100001)]

queue = deque([N])

while queue:
    current = queue.popleft()
    sec = time[current]

    # X-1
    if current - 1 > -1 and sec + 1 < time[current-1]:
        queue.append(current-1)
        time[current-1] = sec + 1
        trace[current-1] = current

    # X+1
    if current + 1 < peak and sec + 1 < time[current+1]:
        queue.append(current+1)
        time[current+1] = sec + 1
        trace[current+1] = current

    # 2X
    if current * 2 < peak and sec + 1 < time[current*2]:
        queue.append(current*2)
        time[current*2] = sec + 1
        trace[current*2] = current

print(time[K])

route = [K]
current = K
while current != N:
    route.append(trace[current])
    current = route[-1]

for i in range(len(route)-1, -1, -1):
    print(route[i], end = ' ')