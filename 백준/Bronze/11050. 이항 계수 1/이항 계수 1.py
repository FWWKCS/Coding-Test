def get_factorial(x) :
    total = 1
    for k in range(2, x+1) :
        total *= k

    return total 

N, K = map(int,input().split())

# n choose k = n! / k!(n-k)!

nCr = get_factorial(N) // (get_factorial(K)*get_factorial(N-K))

print(nCr)