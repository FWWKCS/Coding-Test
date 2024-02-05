import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline

def find_parent(x):
    if x == pointer[x]: return x

    pointer[x] = find_parent(pointer[x])
    return pointer[x]

def union(a, b):
    x = find_parent(a)
    y = find_parent(b)

    if x < y: pointer[y] = x
    else: pointer[x]= y

def is_union(a, b):
    x = find_parent(a)
    y = find_parent(b)
    
    if x == y: return True
    else: return False

N, M = map(int, input().split())
pointer = [i for i in range(N)]
found = 0
for k in range(1, M+1):
    a, b = map(int, input().split())

    if is_union(a, b):
        found = k
        break

    union(a, b)

print(found)