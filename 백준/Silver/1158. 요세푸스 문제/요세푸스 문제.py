import collections

N, K = map(int, input().split())
queue = collections.deque([i for i in range(1,N+1)])

permutation = []

while queue :
    queue.rotate(-(K-1))
    permutation.append(queue.popleft())

print('<', end = '')
for p in range(N) :
    if p != N-1 :
        print(permutation[p], end = ', ')
    else :
        print(permutation[p], end = '>')