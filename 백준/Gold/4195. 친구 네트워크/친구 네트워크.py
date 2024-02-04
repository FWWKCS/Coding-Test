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

    if x < y:
        pointer[y] = x
        root[x] |= root[y]
        del(root[y])
        return x
    else:
        pointer[x] = y
        root[y] |= root[x]
        del(root[x])
        return y

def is_union(a, b):
    x = find_parent(a)
    y = find_parent(b)

    if x == y: return True
    else: return False

T = int(input())
for _ in range(T):
    F = int(input())
    root = {
        # 각 집합의 루트 : { 집합 요소 }
    }

    pointer = {
        # 친구 : 루트
    }

    for _ in range(F):
        a, b = input().split()
        if a not in pointer:
            root[a] = {a}
            pointer[a] = a

        if b not in pointer:
            root[b] = {b}
            pointer[b] = b

        if is_union(a, b):
            parent = find_parent(a)    
        else: 
            parent = union(a, b)
            for node in list(root[parent]):
                if pointer[node] != parent:
                    pointer[node] = parent
        
        print(len(root[parent]))