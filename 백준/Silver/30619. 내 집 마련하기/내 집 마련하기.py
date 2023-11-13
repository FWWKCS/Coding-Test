import collections
N = int(input())
sequence = list(map(int, input().split()))
M = int(input())
for _ in range(M):
    L, R = map(int, input().split())
    tmp = []
    for k in sequence:
        if L <= k and k <= R:
            tmp.append(k)
    
    tmp.sort() 
    queue = collections.deque(tmp)

    # 출력
    for k in sequence:
        if L <= k and k <= R:
            print(queue.popleft(), end = ' ')
        else:
            print(k, end = ' ')
    print()