def check_power(a, b):
    value = abs(a-b)

    if a != 0 and b != 0:
        if value == 1 or value == 3:
            return 3
        elif value == 2:
            return 4
        else: return 1
    else:
        return 2

step = [0] + list(map(int, input().split()))

dp = [[[float('inf') for _ in range(5)] for _ in range(5)] for _ in range(len(step)-1)]
dp[1][0][step[1]] = 2
dp[1][step[1]][0] = 2

for k in range(2, len(step)-1):
    for r in range(5):
        for c in range(5):
            if r != c and dp[k-1][r][c] != float('inf'):
                if step[k] != c:
                    # 왼발이 k번 스텝으로 이동
                    dp[k][step[k]][c] = min(dp[k][step[k]][c], dp[k-1][r][c] + check_power(step[k], r))
                if step[k] != r:
                    # 오른발이 k번 스텝으로 이동
                    dp[k][r][step[k]] = min(dp[k][r][step[k]], dp[k-1][r][c] + check_power(step[k], c))

answer = float('inf')
for r in range(5):
    for c in range(5):
        if r != c:
            answer = min(answer, dp[-1][r][c])

print(answer)