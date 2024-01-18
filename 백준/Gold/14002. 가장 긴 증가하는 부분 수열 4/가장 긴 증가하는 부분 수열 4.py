N = int(input())
sequence = [0] + list(map(int, input().split()))

dp = [0 for _ in range(N+1)]
# dp[i]: i번째 수열까지 가능한 최장 수열 길이
select = [-1 for _ in range(N+1)]
# select[i]: i번 수열은 select[i] 인덱스로부터 연결

for k in range(1, N+1):
    for i in range(k-1, -1, -1):
        if sequence[k] > sequence[i] and dp[i]+1 > dp[k]:
            dp[k] = dp[i]+1
            select[k] = i

print(max(dp))

path = []
current = dp.index(max(dp))
while current != 0:
    path.append(sequence[current])
    current = select[current]
    
print(*path[-1::-1])