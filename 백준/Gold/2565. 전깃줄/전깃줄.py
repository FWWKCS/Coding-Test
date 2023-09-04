import sys
input = sys.stdin.readline

n = int(input())
wires = [(0,0)] + [tuple(map(int, input().split())) for _ in range(n)]
wires = sorted(wires, key = lambda x : x[0])


dp = [0 for _ in range(n+1)]
# dp[i] : i번째 위치까지 겹치지않고 연결 가능한 전선의 최대 개수
dp[1] = 1 

for p in range(2, n+1) :
    maxWire = 0
    for i in range(p-1, -1, -1) :
        # 겹치지 않는 i번째 위치의 전선들 중 dp의 최댓값 + 1
        if wires[p][1] > wires[i][1] :
            maxWire = max(maxWire, dp[i]+1)

    dp[p] = maxWire

print(n-max(dp))