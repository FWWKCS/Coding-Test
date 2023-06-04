# https://www.acmicpc.net/problem/2292


# 시작점 n = 0, 1은 1개
# n = 1, 각 변을 구성하는 노드 총 개수는 6n = 6
# n = 2, 각 변을 구성하는 노드 총 개수는 6n = 12
# n = k 일때, 각 변을 구성하는 노드의 총 개수는 6k

# 1, 7, 19, ...
# 각 층과 대응 ( 0층, 1층, 2층, ...)

findValue = int(input())

sequence = 1 # 0층의 노드 최대값
floor = 0 # 층수 

while (findValue > sequence) : # 각 층 노드의 최댓값과 일치하는 경우도 중단
    sequence += 6*(floor+1)
    floor += 1
    # print(f"지금은 {floor}층이고 이 층의 노드 최댓값은 {sequence}")

print(floor+1) # 0층 1부터 통과하므로 층의 +1





