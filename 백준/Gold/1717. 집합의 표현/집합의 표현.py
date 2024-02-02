import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline

def find_parent(target):
    if target == pointer[target]: return target # 자기자신
    
    pointer[target] = find_parent(pointer[target])
    return pointer[target]

def union(x, y):
    x = find_parent(a)
    y = find_parent(b)

    if x == y: return # 같은 부모에 연결되어있음

    if x < y: pointer[y] = x # 더 작은 값이 루트가 된다
    else: pointer[x] = y 

def is_union(x, y):
    x = find_parent(a)
    y = find_parent(b)

    if x == y: return True
    else: return False

n, m = map(int, input().split())
pointer = [i for i in range(n+1)] # 처음엔 자기자신을 지목
for _ in range(m):
    q, a, b = map(int, input().split())

    if q == 0: union(a, b)
    else: 
        if is_union(a, b): print('YES')
        else: print('NO')