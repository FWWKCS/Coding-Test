import sys
input = sys.stdin.readline

def valid(r, c):
    value = board[r][c]
    
    # 행 검사
    for i in range(9):
        if i == c: continue
        if board[r][i] == value: return False

    # 열 검사
    for i in range(9):
        if i == r: continue
        if board[i][c] == value: return False

    # 블럭 검사
    ROW = 3 * (r // 3)    
    COL = 3 * (c // 3)
    for i in range(ROW, ROW+3):
        for j in range(COL, COL+3):
            if i == r and j == c: continue
            if board[i][j] == value: return False

    return True

def sudoku(idx):
    if idx == len(target): 
        for r in range(9):
            for c in range(9):
                print(board[r][c], end = '')
            print()
        sys.exit()

    r, c = target[idx]

    for x in range(1, 10):
        board[r][c] = x
        if valid(r, c):
            sudoku(idx + 1)
        board[r][c] = 0

board = []
for _ in range(9):
    line = list(map(int, list(input().rstrip())))
    board.append(line)

target = []

for r in range(9):
    for c in range(9):
        if board[r][c] == 0:
            target.append((r, c))

sudoku(0)