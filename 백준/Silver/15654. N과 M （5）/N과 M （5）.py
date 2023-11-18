import sys
input = sys.stdin.readline

def backtracking(depth, get):
    global num
    if depth == M: 
        print(*get)

    for k in num:
        if k not in get:
            get.append(k)
            backtracking(depth+1, get)
            get.pop()

N, M = map(int, input().split())
num = sorted(list(map(int, input().split())))

backtracking(0, [])