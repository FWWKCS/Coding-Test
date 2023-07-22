import sys
input = sys.stdin.readline

x = int(input())

memoization = [0 for _ in range(x+1)] # [ 각 인덱스의 값을 1로 만드는 최소한의 연산 횟수 ]
             
for i in range(2, x+1) : # 2부터 x까지 연산
    # 현재 수에서 1을 빼는 경우
    memoization[i] = memoization[i-1] + 1 # 연산 횟수를 1증가

    # 현재 수가 3으로 나누어 떨어지는 경우
    if i % 3 == 0 :
        # 1을 뺀 것과 i에서 3으로 한 번 더 나눈 것 중에 최소가 되는 것으로 초기화
        # i는 부분 문제인 i // 3의 값이 되기 위해 3으로 한 번 더 나누므로 가장 근접한 부분 문제의 값에 1을 증가 
        memoization[i] = min(memoization[i], memoization[i // 3] + 1)

    # 현재 수가 2로 나누어 떨어지는 경우
    if i % 2 == 0 :
        memoization[i] = min(memoization[i], memoization[i // 2] + 1)

print(memoization[x])

