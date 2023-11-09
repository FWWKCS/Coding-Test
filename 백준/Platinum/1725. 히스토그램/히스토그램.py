N = int(input())
histogram = [0] + [int(input()) for _ in range(N)] + [0]

S = 0
stack = [0]
for k in range(1, N+2):
    top = stack[-1]
    if histogram[top] <= histogram[k]:
        stack.append(k)
    else:
        while histogram[k] < histogram[stack[-1]] :
            pos = stack.pop()
            S = max(S, (k-stack[-1]-1) * histogram[pos])
        stack.append(k)

print(S)