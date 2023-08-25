import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000)

def findValidValue(r, c, selected) :
    global board
    # 가로 탐색
    for i in range(9) :
        if board[r][i] == selected : return False

    # 세로 탐색
    for i in range(9) :
        if board[i][c] == selected : return False
        # 위에서 이미 제거된 수는 스킵

    # 대각선 소거 ( 구간 나눠 반복문 구분 )
    x = (c // 3) * 3 
    y = (r // 3) * 3    

    for i in range(y,y+3) :
        for j in range(x, x+3) :
            if board[i][j] == selected : return False

    # 모든 조건을 충족
    return True

def sudoku(depth) :
    global put, board

    # 조건을 모두 만족하고 다 채웠으면 결과를 출력하고 종료
    if depth == len(put) :
        for b in board :
            print(*b)
        sys.exit()

    # 채워야할 인덱스 결정
    current_R = put[depth][0]
    current_C = put[depth][1]
 
    # 1부터 9까지 조건을 만족하는 숫자 탐색
    for k in range(1,10) :
        if findValidValue(current_R, current_C, k) : 
            # 대입 가능한 수를 board에 추가
            board[current_R][current_C] = k
            sudoku(depth+1)
            # 복구
            board[current_R][current_C] = 0


board = [list(map(int, input().split())) for _ in range(9)]

# 채워야 할 곳 탐색
put = []
for r in range(9) :
    for c in range(9) :
        if board[r][c] == 0 :
            put.append((r,c))

sudoku(0)
