import collections

def findDestination(r,c) :
    queue = collections.deque([(0,r,c)]) # ( 이동 횟수, 행, 열 )
    visited = [[False for _ in range(C)] for _ in range(R)]
    visited[r][c] = True

    move = 0

    # 각 시작점부터 하나씩 상하좌우로 이동하며 탐색
    while len(queue) != 0 :
        current = queue.popleft()
        move = current[0]
        r = current[1]
        c = current[2]

        if r-1 >= 0 and landmap[r-1][c] == 'L' and not visited[r-1][c] : 
            visited[r-1][c] = True
            queue.append((move+1, r-1, c))
        if r+1 <= R-1 and landmap[r+1][c] == 'L' and not visited[r+1][c] :
            visited[r+1][c] = True
            queue.append((move+1, r+1, c))
        if c-1 >= 0 and landmap[r][c-1] == 'L' and not visited[r][c-1] : 
            visited[r][c-1] = True
            queue.append((move+1, r, c-1))
        if c+1 <= C-1 and landmap[r][c+1] == 'L' and not visited[r][c+1] : 
            visited[r][c+1] = True
            queue.append((move+1, r, c+1))

    return move

        
R, C = map(int, input().split())

landmap = []
time = 0 # 최대로 가질 값

for _ in range(R) :
    line = list(input())
    landmap.append(line)

for r in range(R) :
    for c in range(C) :
        if landmap[r][c] == 'L' :
            time = max(time, findDestination(r,c))
    
print(time)