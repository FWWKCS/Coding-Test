import math

N = int(input())

# 에라토스테네스의 체
prime = [x for x in range(N+1)]
prime[1] = 0

for i in range(2, math.isqrt(N)+1):
    for j in range(i**2, N+1, i):
        prime[j] = 0

prime = sorted(list(set(prime)))
L = len(prime)

# 누적합
prefix = [0 for _ in range(L)]
for i in range(1, L):
    prefix[i] = prefix[i-1] + prime[i]

# 투 포인터
s, e = 1, 1
count = 0

while s < L:
    if e >= L:
        e = min(e, L-1)
        s += 1

    total = prefix[e] - prefix[s-1]
    if total < N:
        e += 1
    elif total > N:
        s += 1
    else: # total == N
        count += 1
        s += 1

print(count)