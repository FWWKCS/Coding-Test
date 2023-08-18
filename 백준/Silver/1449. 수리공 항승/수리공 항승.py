import sys
input = sys.stdin.readline

N, L = map(int, input().split())
position = list(map(int, input().split()))
position.sort()

tape = 0 # 테이프 개수

index = 0
while index != N :
    distance = position[index] - 0.5 + L

    for k in position[index+1:] :
        if distance >= k + 0.5 :
            index += 1
        else : break
    
    tape += 1
    index += 1

print(tape)