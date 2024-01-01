N = int(input())
A = [0] + list(map(int, input().split()))
F = [0 for _ in range(1000001)]
# F[i]: A에서 i가 나온 개수
for a in A: F[a] += 1

stack = [(0,0)]
NGF = [-1 for _ in range(N+1)]

for k in range(1, N+1):
    current = A[k]

    while stack and F[stack[-1][0]] < F[current]:
        value, index = stack.pop()
        NGF[index] = current

    stack.append((current, k))

print(*NGF[1:])