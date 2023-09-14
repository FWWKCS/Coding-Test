import sys
input = sys.stdin.readline

N, K = map(int, input().split())
arr = list(map(int, input().split()))


result = sum(arr[:K])
memo = result

for i in range(K, N) :
    memo = memo+arr[i]-arr[i-K]
    result = max(result, memo)

print(result)