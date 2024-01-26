import sys
input = sys.stdin.readline

N = int(input())
W = int(input())
events = [0] + [tuple(map(int, input().split())) for _ in range(W)]

dp = [[float('inf') for _ in range(W+1)] for _ in range(W+1)]
# dp[r][c]: 1번 경찰차가 마지막으로 r번 사건을 처리, 2번 경찰차가 마지막으로 c번 사건을 처리
dp[0][0] = 0

trace = [[(-1, -1) for _ in range(W+1)] for _ in range(W+1)]

def dist(s, e, who):
    if who == 1 and s == 0: # 1번 경찰차
        return abs(1-events[e][0]) + abs(1-events[e][1])
    elif who == 2 and s == 0: # 2번 경찰차
        return abs(N-events[e][0]) + abs(N-events[e][1])
    else:
        return abs(events[s][0]-events[e][0]) + abs(events[s][1]-events[e][1])
    
for k in range(1, W+1):
    dp[k][0] = dp[k-1][0] + dist(k-1, k, 1)
    trace[k][0] = (k-1, 0)

    dp[0][k] = dp[0][k-1] + dist(k-1, k, 2)
    trace[0][k] = (0, k-1)

for r in range(1, W+1):
    for c in range(1, W+1):
        if r == c: continue
        
        fixed = -1
        if r < c: fixed = 1
        else: fixed = 2
        # |r-c| = 1,
        if abs(r-c) == 1: 
            if fixed == 1: # 1번 경찰차 고정
                for k in range(c-2, -1, -1):
                    l = dist(k, c, 3-fixed)
                    if dp[r][k] + l < dp[r][c]:
                        dp[r][c] = dp[r][k] + l
                        trace[r][c] = (r, k)
            else: # 2번 경찰차 고정
                for k in range(r-2 ,-1 ,-1):
                    l = dist(k, r, 3-fixed)
                    if dp[k][c] + l < dp[r][c]:
                        dp[r][c] = dp[k][c] + l
                        trace[r][c] = (k, c)
        
        # |r-c| > 1
        else:
            if fixed == 1:
                dp[r][c] = min(dp[r][c], dp[r][c-1] + dist(c-1, c, 3-fixed))
                trace[r][c] = (r, c-1) 
            else:
                dp[r][c] = min(dp[r][c], dp[r-1][c] + dist(r-1, r, 3-fixed))
                trace[r][c] = (r-1, c)

seq = [0]
current = (int(10e9), int(10e9))

max_l = int(10e9)
# 1번 차량 or 2번 차량이 4번까지 모두 처리할 때의 최단거리
for i in range(W):
    if dp[W][i] < max_l:
        max_l = dp[W][i]
        current = trace[W][i]
        seq[0] = 1
    
    if dp[i][W] < max_l:
        max_l = dp[i][W]
        current = trace[i][W]
        seq[0] = 2

print(max_l)

while current != (0, 0):
    row, col = trace[current[0]][current[1]]
    # 행 방향 이동이면 1
    if row < current[0]:
        seq.append(1)
    # 열 방향 이동이면 2
    else:
        seq.append(2)

    current = (row, col)

for i in range(W-1, -1, -1): print(seq[i])