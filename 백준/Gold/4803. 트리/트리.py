import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

def find_parent(target):
    if target == pointer[target]: return target

    pointer[target] = find_parent(pointer[target]) # 경로 압축
    return pointer[target]

def union(a, b):
    x = find_parent(a)
    y = find_parent(b)

    if x < y: pointer[y] = x
    else: pointer[x] = y

def is_union(a, b):
    x = find_parent(a)
    y = find_parent(b)

    if x == y: return True
    else: return False    

case_count = 1
while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0: break

    cycled = set()
    pointer = [i for i in range(0, n+1)]
    T = 0
    for _ in range(m): 
        a, b = map(int, input().split())
        if is_union(a, b):
            cycled |= {a, b}
            continue

        union(a, b)

    cycled_parent = set()
    for i in range(1, n+1): find_parent(i)
    for i in cycled: cycled_parent.add(find_parent(i)) 
    T = len(set(pointer)-{0}) - len(cycled_parent)

    if T == 0: print(f'Case {case_count}: No trees.')
    elif T == 1: print(f'Case {case_count}: There is one tree.')
    else: print(f'Case {case_count}: A forest of {T} trees.')
    case_count += 1