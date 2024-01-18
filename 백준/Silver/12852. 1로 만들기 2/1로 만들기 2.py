N = int(input())

dp = [float('inf') for _ in range(N+1)]
dp[0], dp[1] = 0, 0
# dp[i]: i까지 가능한 최소 연산
select = [0 for _ in range(N+1)]
# select[i]: i를 갱신하는데 영향을 준 dp 인덱스

for k in range(2, N+1):
    if k % 3 == 0 and dp[k//3]+1 < dp[k]:
        dp[k] = dp[k//3]+1
        select[k] = k//3
    
    if k % 2 == 0 and dp[k//2]+1 < dp[k]:
        dp[k] = dp[k//2]+1
        select[k] = k//2

    if dp[k-1]+1 < dp[k]:
        dp[k] = dp[k-1]+1
        select[k] = k-1
    
print(dp[-1])
current = N
while current != 0:
    print(current, end = ' ')
    current = select[current]