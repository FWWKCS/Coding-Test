import sys
input = sys.stdin.readline

def move(r, c, visitedLetter, moveCount) :
    global maximumMove
    if r < 0 or r > R-1 or c < 0 or c > C-1 : return
    if visitedLetter[ord(board[r][c])-65] : 
        maximumMove = max(maximumMove, moveCount)
        return
    
    visitedLetter[ord(board[r][c])-65] = True

    move(r-1, c, visitedLetter, moveCount+1) # 복사된 별개의 리스트를 전달
    move(r+1, c, visitedLetter, moveCount+1)
    move(r, c-1, visitedLetter, moveCount+1)
    move(r, c+1, visitedLetter, moveCount+1)

    visitedLetter[ord(board[r][c])-65] = False

R, C = map(int, input().split())

board = []

for _ in range(R) :
    line = list(input().rstrip())
    board.append(line)

maximumMove = 1

visitedLetter = [False]*26

move(0,0,visitedLetter, 0)

print(maximumMove)