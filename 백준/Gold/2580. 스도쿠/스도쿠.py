import collections
import sys
sys.setrecursionlimit(10000)

def elimination(r, c, check) :
    global board
    # 가로 소거
    for i in range(9) :
        if board[r][i] == 0 : continue

        check[board[r][i]-1] = True

    # 세로 소거
    for i in range(9) :
        if board[i][c] == 0 : continue
        # 위에서 이미 제거된 수는 스킵
        if check[board[i][c]-1] : continue

        check[board[i][c]-1] = True

    # 대각선 소거 ( 구간 나눠 반복문 구분 )
    x, y = -1, -1 # 각 블럭의 시작좌표
    if r <= 2 and c <= 2 : 
        x, y = 0, 0
    elif r <= 2 and c >= 3 and c <= 5 : 
        x, y = 3, 0
    elif r <= 2 and c >= 6 : 
        x, y = 6, 0
    elif r >= 3 and r <= 5 and c <= 2 : 
        x, y = 0, 3
    elif r >= 3 and r <= 5 and c >= 3 and c <= 5 : 
        x, y = 3, 3
    elif r >= 3 and r <= 5 and c >= 6 :
        x, y = 6, 3
    elif r >= 6 and c <= 2 :
        x, y = 0, 6
    elif r >= 6 and c >= 3 and c <= 5 :
        x, y = 3, 6
    elif r >= 6 and c >= 6 :
        x, y = 6, 6

    for i in range(y,y+3) :
        for j in range(x, x+3) :
            if board[i][j] == 0 : continue

            if check[board[i][j]-1] : continue

            check[board[i][j]-1] = True
        
    # 완성된 check 리턴
    return check

def sudoku(depth) :
    global put, board

    # 조건을 모두 만족하고 다 채웠으면 결과를 출력하고 종료
    if depth == len(put) :
        for r in range(9) :
            for c in range(9) :
                print(board[r][c], end = ' ')
            print()
        sys.exit()

    # 채워야할 인덱스 결정
    current_R = put[depth][0]
    current_C = put[depth][1]

    # 1부터 9중 가능한 숫자만 남긴 후 재귀 호출 ( 소거법 )
    check = [False for _ in range(9)] 
    check = elimination(current_R, current_C, check)

    for k in range(1,10) :
        if check[k-1] : continue

        # 대입 가능한 수를 board에 추가
        board[current_R][current_C] = k
        sudoku(depth+1)
        # 복구
        board[current_R][current_C] = 0

board = []
for _ in range(9) :
    line = list(map(int, input().split()))
    board.append(line)

# 채워야 할 곳 탐색
put = collections.deque([])
for r in range(9) :
    for c in range(9) :
        if board[r][c] == 0 :
            put.append((r,c))

sudoku(0)