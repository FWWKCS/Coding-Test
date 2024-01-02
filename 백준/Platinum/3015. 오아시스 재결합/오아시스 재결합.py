import sys
input = sys.stdin.readline

N = int(input())
line = [int(input()) for _ in range(N)]

stack = [[line[0], 1]]
# stack을 내림차순으로 push
count = 0

for i in range(1, N):
    current = line[i]

    # top보다 큰 수가 들어오는 경우
    while stack and stack[-1][0] < current:
        value = stack.pop()[1]
        count += value

    # 같은 수가 들어올 때
    if stack and stack[-1][0] == current:
        value = stack.pop()[1]
        count += value

        # 스택이 비지 않는 경우
        if stack: 
            count += 1 # current 보다 1번 큰 수와 매치가능한 경우를 더한다

        stack.append((current, value+1))
    # 작은 수가 들어올 때
    else:
        if stack:
            count += 1 # current와 매치하는 경우(오직 1가지)를 더한다

        stack.append((current, 1))

print(count)