import math
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
arr = list(map(int, input().split()))

# 누적합 리스트
p_arr = [0 for _ in range(N)]
p_arr[0] = arr[0]
for k in range(1, N) :
    p_arr[k] = p_arr[k-1] + arr[k]

# 나머지 그룹 생성
remain = [[] for _ in range(M)]
# remain[i] : p_arr[x]를 M으로 나눈 나머지가 i인 경우

for i in range(N) :
    remain[p_arr[i] % M].append(p_arr[i])

# 쌍의 개수 연산
twin = len(remain[0]) # 나머지가 0인 누적합값까지의 개수
for i in range(M) :
    # 나머지가 동일한 누적합 값끼리의 차를 M으로 나눴을때의 나머지는 0
    # 같은 인덱스의 요소 개수 중 2개를 선택하는 경우의 수
    if len(remain[i]) > 1 :
        n = len(remain[i])
        twin += math.comb(n, 2) # n choose 2

print(twin)