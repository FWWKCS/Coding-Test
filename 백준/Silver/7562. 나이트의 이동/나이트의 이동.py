import collections

def findDestination(board, rs, cs, rd, cd) :
    queue = collections.deque([(0,rs,cs)]) # ( 이동 횟수, 행, 열 )

    # 각 시작점부터 하나씩 상하좌우로 이동하며 탐색
    while len(queue) != 0 :
        current = queue.popleft()
        move = current[0]
        r = current[1]
        c = current[2]

        if r == rd and c == cd : 
            return move
        

        # 위로 2칸 이동
        if r - 2 >= 0  :
            if c - 1 >= 0 and board[r-2][c-1] == 0 : 
                board[r-2][c-1] = 1
                queue.append((move+1, r-2, c-1))
            if c + 1 <= l-1 and board[r-2][c+1] == 0 : 
                board[r-2][c+1] = 1
                queue.append((move+1, r-2, c+1))
        
        # 아래로 2칸 이동
        if r + 2 <= l-1 :
            if c - 1 >= 0 and board[r+2][c-1] == 0 : 
                board[r+2][c-1] = 1
                queue.append((move+1, r+2, c-1))
            if c + 1 <= l-1 and board[r+2][c+1] == 0 : 
                board[r+2][c+1] = 1
                queue.append((move+1, r+2, c+1))

        # 왼쪽으로 2칸 이동
        if c - 2 >= 0 :
            if r - 1 >= 0 and board[r-1][c-2] == 0 :
                board[r-1][c-2] = 1
                queue.append((move+1, r-1, c-2))
            if r + 1 <= l-1 and board[r+1][c-2] == 0 :
                board[r+1][c-2] = 1
                queue.append((move+1, r+1, c-2))
        
        # 오른쪽으로 2칸 이동
        if c + 2 <= l-1 :
            if r - 1 >= 0 and board[r-1][c+2] == 0 :
                board[r-1][c+2] = 1
                queue.append((move+1, r-1, c+2))
            if r + 1 <= l-1 and board[r+1][c+2] == 0 :
                board[r+1][c+2] = 1
                queue.append((move+1, r+1, c+2))


testCase = int(input())

for _ in range(testCase) :
    l = int(input())
    board = [[0 for _ in range(l)] for _ in range(l)]

    rs, cs = map(int, input().split())
    rd, cd = map(int, input().split())
    
    board[rs][cs] = 1

    print(findDestination(board, rs, cs, rd, cd))
