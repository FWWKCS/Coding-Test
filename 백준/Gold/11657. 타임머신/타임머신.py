import sys
input = sys.stdin.readline

N, M = map(int, input().split())
edge = [tuple(map(int, input().split())) for _ in range(M)]
distance = [int(10e9) for _ in range(N+1)]
distance[1] = 0 # 시작점

# 벨만-포드
for i in range(N):
    for s, e, w in edge:
        if distance[s] != int(10e9) and distance[s]+w < distance[e]:
            if i == N-1: # 무한 순환 여부
                print(-1)
                exit()
                
            distance[e] = distance[s]+w

for i in range(2, N+1):
    if distance[i] == int(10e9): 
        print(-1)
        continue
    print(distance[i])