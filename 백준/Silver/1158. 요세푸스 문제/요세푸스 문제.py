import collections

N, K = map(int, input().split())
queue = collections.deque([i for i in range(1, N+1)])

# 순환
permutation = []
while queue :
    queue.rotate(-(K-1))
    permutation.append(queue.popleft())

# 형식 출력
print('<', end = '')
for p in permutation[:N-1] : print(p, end = ', ')
print(permutation[-1], end = '>')