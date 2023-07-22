import sys
input = sys.stdin.readline

testCase = int(input())

for _ in range(testCase) :
    R, N = map(int, input().split()) # n choose r

    memoization = [[0 for _ in range(R+1)] for _ in range(N+1)]
    for h in range(N+1) :
        memoization[h][0] = 1
    
    for n in range(1, N+1) :
        for r in range(1, R+1) :
            if n < r : break

            # 조합의 성질 
            # n choose k = n-1 choose k + n-1 choose k-1
            memoization[n][r] = memoization[n-1][r] + memoization[n-1][r-1]

    print(memoization[N][R])