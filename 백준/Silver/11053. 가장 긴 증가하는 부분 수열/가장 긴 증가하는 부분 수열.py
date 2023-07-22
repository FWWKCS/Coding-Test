import sys
input = sys.stdin.readline

size = int(input())

A = list(map(int, input().split())) # permutation

maxValue = 0

# 동적 계획법
# 각 인덱스에 대해 처음 길이는 1
dp = [1 for _ in range(size)]

# 각 인덱스 값이 이전 인덱스들보다 크면 이어지는 수열이 되므로
# j 인덱스 dp 값 + 1과 자기자신의 값 중 최댓값으로 초기화
for i in range(1, size) :
    for j in range(i) :
        if A[i] > A[j] : 
            dp[i] = max(dp[i], dp[j] + 1)

print(max(dp))
