N = int(input())
sequence = [0] + list(map(int, input().split()))

stack = [(0,0)] 
# (a, b): 스택에 들어올 수 c에 대해 c > a 이면 NGE(b) = c가 된다  
NGE = [-1 for _ in range(N+1)]

for i in range(1, N+1):
    current = sequence[i]

    while stack and stack[-1][0] < current:
        value, index = stack.pop()
        NGE[index] = current
    
    stack.append((current, i))

print(*NGE[1:])