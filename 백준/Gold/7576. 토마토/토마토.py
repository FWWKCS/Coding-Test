import collections

def ripenTomatoes() :
    global time
    queue = collections.deque([])

    # 시작점 탐색
    for r in range(N) :
        for c in range(M) :
            if box[r][c] == 1 : queue.append((0, r, c)) # ( 경과시간, 행, 열 )

    # 각 시작점부터 하나씩 상하좌우로 이동하며 탐색
    while len(queue) != 0 :
        tomato = queue.popleft()
        dt = tomato[0]
        r = tomato[1]
        c = tomato[2]

        time = max(time, dt)

        if r > 0 and box[r-1][c] == 0 :
            box[r-1][c] = 1
            queue.append((dt+1, r-1, c))
        if r < N-1 and box[r+1][c] == 0 :
            box[r+1][c] = 1
            queue.append((dt+1, r+1, c))
        if c > 0 and box[r][c-1] == 0 :
            box[r][c-1] = 1
            queue.append((dt+1, r, c-1))
        if c < M-1 and box[r][c+1] == 0 :
            box[r][c+1] = 1
            queue.append((dt+1, r, c+1))


M, N = map(int, input().split())

box = []

for _ in range(N) :
    line = list(map(int, input().split()))
    box.append(line)

time = 0

ripenTomatoes()

complete = True
# 익지않은 토마토가 있는지 확인
for r in range(N) :
    for c in range(M) :
        if box[r][c] == 0 :
            complete = False
            break

    if not complete : break

if complete : print(time)
else : print(-1)
