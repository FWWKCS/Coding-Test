import sys
input = sys.stdin.readline

def fibo_DP(n) :
    global memoization, dpCount
    memoization[1], memoization[2] = 1, 1

    for i in range(3,n+1) :
        dpCount += 1
        memoization[i] = memoization[i-2] + memoization[i-1]

N = int(input())

memoization = [0] * (N + 1)

dpCount = 0

fibo_DP(N)

print(memoization[-1], dpCount)