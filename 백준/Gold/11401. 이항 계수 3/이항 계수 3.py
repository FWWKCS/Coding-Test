def factorial_mod(N):
    value = 1
    for i in range(1, N+1):
        value = (value * i) % MOD
    
    return value

def split_exponent(B, E):
    if E == 1: return B % MOD

    tmp = split_exponent(B, E//2)

    if E % 2 != 0: 
        return (tmp * tmp * B) % MOD
    else :
        return (tmp * tmp) % MOD


N, K = map(int, input().split())
MOD = 1000000007

# n choose k = n!/(k!(n-k)!)
# (n choose k) % MOD 
# n! = A, (k!(n-k)!) = B,

# (AB^-1) % MOD = [(A % MOD)(B^-1 % MOD)] % MOD

# 페르마의 소정리에 의해 
# B^-1 % MOD = B^(MOD-2) % MOD 와 같다

# n!의 나머지 값 구하기
A = factorial_mod(N)

# k!와 (n-k)!의 나머지 값과 최종 곱의 나머지 구하기
B = (factorial_mod(K) * factorial_mod(N-K)) % MOD

# 제곱수의 나머지 구하기
B_exponent = split_exponent(B, MOD-2)

# 최종 곱의 나머지 구하기
print((A*B_exponent) % MOD)