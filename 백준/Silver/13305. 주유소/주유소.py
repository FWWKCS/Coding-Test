N = int(input())

distance = list(map(int, input().split()))
nodes = list(map(int, input().split()))

cost = 0 

start = nodes[0]
index = 1 # 이동 노드

while index != N :
    # 출발점보다 작은 노드를 발견할 때까지 이동
    cost += start * distance[index-1]
    # 만나면 그 지점에서 정차
    if nodes[index] < start :
        start = nodes[index]

    index += 1

print(cost)