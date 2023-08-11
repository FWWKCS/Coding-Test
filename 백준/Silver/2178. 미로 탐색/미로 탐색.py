import collections

def findDestination() :
    global time
    queue = collections.deque([(1,0,0)]) # ( 지나간 블럭, 행, 열 )
    maze[0][0] = 'X'
    total = 10001 # 최종 블럭

    # 각 시작점부터 하나씩 상하좌우로 이동하며 탐색
    while len(queue) != 0 :
        position = queue.popleft()
        blocks = position[0]
        if position[1] == M-1 and position[2] == N-1 : 
            total = min(total, blocks)
            return total
        
        r = position[1]
        c = position[2]

        if r > 0 and maze[r-1][c] == 1 :
            maze[r-1][c] = 'X'
            queue.append((blocks+1, r-1, c))
        if r < M-1 and maze[r+1][c] == 1 :
            maze[r+1][c] = 'X'
            queue.append((blocks+1, r+1, c))
        if c > 0 and maze[r][c-1] == 1 :
            maze[r][c-1] = 'X'
            queue.append((blocks+1, r, c-1))
        if c < N-1 and maze[r][c+1] == 1 :
            maze[r][c+1] = 'X'
            queue.append((blocks+1, r, c+1))

    return blocks



M, N = map(int, input().split())

maze = []

for _ in range(M) :
    line = list(map(int, input()))
    maze.append(line)

print(findDestination())