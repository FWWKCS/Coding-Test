from decimal import Decimal
import sys
input = sys.stdin.readline

def find_parent(x):
    if x == idx_pointer[x]: return x

    idx_pointer[x] = find_parent(idx_pointer[x])
    return idx_pointer[x]

def union(a, b):
    x = find_parent(a)
    y = find_parent(b)

    if x < y: idx_pointer[y] = x
    else: idx_pointer[x] = y

def is_union(a, b):
    x = find_parent(a)
    y = find_parent(b)
    
    if x == y: return True
    else: return False

N, M = map(int, input().split())

pos = [(-1,-1)] + [tuple(map(int, input().split())) for _ in range(N)]
idx_pointer = [i for i in range(N+1)]

# M개의 미리 연결된 그래프 표현
for _ in range(M):
    a, b = map(int, input().split())
    union(a, b)

edges = []
for i in range(1, N):
    for j in range(i+1, N+1):
        d = ((pos[i][0]-pos[j][0])**Decimal('2') + (pos[i][1]-pos[j][1])**Decimal('2')).sqrt()
        edges.append((d, i, j))

edges.sort(key = lambda x : x[0])

total = Decimal('0')
for d, i, j in edges:
    if is_union(i, j): continue
    union(i, j)
    total += d

print(total.quantize(Decimal('0.01')))