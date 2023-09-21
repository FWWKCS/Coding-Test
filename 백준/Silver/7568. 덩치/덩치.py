import sys
input = sys.stdin.readline

N = int(input())

info = [tuple(map(int, input().split())) for _ in range(N)]
rank = [1 for _ in range(N)]
# rank[i] : i번째 사람의 등수

for k in range(1, N) :
    my_weight = info[k][0]
    my_height = info[k][1]
    for i in range(k-1, -1, -1) :
        your_weight = info[i][0]
        your_height = info[i][1]
        
        # 자신이 더 크면 상대의 rank + 1
        if my_weight > your_weight and my_height > your_height :
            rank[i] += 1
        
        # 자신이 더 작으면 자신의 rank + 1
        elif my_weight < your_weight and my_height < your_height :
            rank[k] += 1

        # 비교불가 시 보류

print(*rank)