def solution(board):
    answer = 0
    
    bomb = []
    
    for r in range(len(board)):
        for c in range(len(board)):
            if board[r][c] == 1:
                bomb.append((r, c))
    
    for r, c in bomb:
        if r > 0: 
            board[r-1][c] = 1
            if c > 0: board[r-1][c-1] = 1
            if c < len(board)-1: board[r-1][c+1] = 1
        if r < len(board)-1: 
            board[r+1][c] = 1
            if c > 0: board[r+1][c-1] = 1
            if c < len(board)-1: board[r+1][c+1] = 1
        if c > 0: board[r][c-1] = 1
        if c < len(board)-1: board[r][c+1] = 1
    
    for line in board:
        for x in line:
            if x == 0: answer += 1
    
    return answer