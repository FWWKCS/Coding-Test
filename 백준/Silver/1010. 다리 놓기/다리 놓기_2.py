def get_factorial(x) :
    total = 1
    for k in range(2, x+1) :
        total *= k

    return total 

testCase = int(input())

# 동쪽 N개의 지점 중에 k개의 서쪽 지점 수만큼 선택만 하면 순서대로 연결이 가능 
for _ in range(testCase) :
    K, N = map(int,input().split())

    # n choose k = n! / k!(n-k)!
    nCr = get_factorial(N) // (get_factorial(K)*get_factorial(N-K))

    print(nCr)
