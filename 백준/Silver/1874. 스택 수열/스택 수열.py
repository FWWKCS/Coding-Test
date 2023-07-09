import sys
input = sys.stdin.readline

N = int(input())

target = []
stack = []
sequence = [] # pop을 통해 만들어진 수열
solution = [] # + - 의 순서를 기록 및 출력
current = 0 # 타깃의 인덱스

for _ in range(N) :
    target.append(int(input()))

for k in range(1,N+1) :
    stack.append(k)
    solution.append('+')
    while len(stack) > 0 :
        if stack[len(stack)-1] == target[current] :
            sequence.append(stack.pop())
            current += 1
            solution.append('-')
        else : break

if target == sequence : 
    for s in solution : print(s)
else : print('NO')