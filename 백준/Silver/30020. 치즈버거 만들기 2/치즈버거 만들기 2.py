import sys
input = sys.stdin.readline

def makeBurger(log) :
    for l in log :
        print('ab'*l[1] + 'a')

isFound = False

def dfs(pa, ch) :
    global log, isFound

    if isFound or (pa > 0 and ch <= 0) or (pa > 2*ch) : return

    if pa == ch + 1 :
        print('YES')
        log.append((pa,ch))
        print(len(log))
        makeBurger(log)
        isFound = True
        return 

    for k in range(ch+1, 1, -1) :
        if isFound : break
        log.append((k, k-1))
        dfs(pa-k, ch-(k-1))
        log.pop()


N, M = map(int, input().split())

# 치즈가 패티보다 많으면 절대 불가능
# 한 버거에 패티와 치즈를 최소한으로 사용할 때 패티가 치즈보다 지나치게 많으면 불가능

log = []

if N > M and N <= 2*M: 
    dfs(N, M)

if not isFound : print('NO')