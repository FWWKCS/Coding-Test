N = int(input())
if N == 1: 
    print(1)
else:
    num = [i for i in range(1, N+1)]
    left = [k for k in num if k % 2 != 0]
    right = [k for k in num if k % 2 == 0]

    right.sort(reverse=True)

    for k in left+right:
        print(k, end= ' ')