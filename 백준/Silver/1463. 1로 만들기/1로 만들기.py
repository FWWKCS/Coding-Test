N = int(input())
memo = [1e9 for _ in range(N+1)]
# 초기 정보 정의
memo[1] = 0

for i in range(2, N+1):
    if i % 3 == 0:
        memo[i] = min(memo[i], memo[i // 3]+1)

    if i % 2 == 0:
        memo[i] = min(memo[i], memo[i // 2]+1)

    memo[i] = min(memo[i], memo[i-1]+1)

print(memo[N]) # 결과 반환