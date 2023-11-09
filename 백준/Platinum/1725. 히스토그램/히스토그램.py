import sys
input = sys.stdin.readline

N = int(input())
histogram = [0] + [int(input()) for _ in range(N)] + [0]

# 1. push 하려는 막대의 높이가 스택의 top값 이상이면 push
# 2. push 하려는 막대의 높이가 스택의 top값 미만이면 
# push를 할 수 있을때까지 스택을 하나씩 pop하며 최대 넓이 구하기

S = 0 # 최대 면적값
stack = [0]
for k in range(1, N+2):
    top = stack[-1]
    if histogram[top] <= histogram[k]:
        stack.append(k)
    else:
        # 현재 높이가 top값 인덱스의 높이보다 크거나 같을 때까지 
        # pop하면서 넓이를 계산
        while histogram[k] < histogram[stack[-1]] :
            pos = stack.pop()
            S = max(S, (k-stack[-1]-1) * histogram[pos])

        stack.append(k)

print(S)