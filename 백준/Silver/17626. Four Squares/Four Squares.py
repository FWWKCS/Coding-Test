dp = [5 for i in range(50001)]
# dp[i] : i를 만드는데 필요한 최소 개수의 제곱수
dp[0] = 0

# k^2수는 무조건 1
for k in range(1, int(50000 ** 0.5) + 1) :
    dp[k**2] = 1

for k in range(50001) :
    if dp[k] == 1 : continue

    num = int(k ** 0.5)
    for i in range(num, (num//2), -1) :
        dp[k] = min(dp[k], dp[i**2] + dp[k-(i**2)])

n = int(input())
print(dp[n])