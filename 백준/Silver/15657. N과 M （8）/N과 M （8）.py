import sys
input = sys.stdin.readline

def backtracking(depth, get, top):
    global num
    if depth == M: 
        print(*get)
        return

    for k in num:
        if k >= top:
            get.append(k)
            backtracking(depth+1, get, k)
            get.pop()

N, M = map(int, input().split())
num = sorted(list(map(int, input().split())))

backtracking(0, [], -1)