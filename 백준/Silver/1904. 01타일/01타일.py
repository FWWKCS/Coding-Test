N = int(input())

combination = [0] * (N+1)

combination[0] = 1 # N = 1, 1 ( 1 )
combination[1] = 1 # N = 2, 2 ( 11, 00 )

# N = 3, 3 ( 111, 100, 001 )
# N = 4, 5 ( 1111, 1100, 1001, 0011, 0000 )
# N = 5, 8
# N = 6, 13

# N >= 3, combination[N] = combination[N-1] + combination[N-2]

for i in range(2, N+1) :
    combination[i] = (combination[i-1]+combination[i-2]) % 15746

print(combination[N])