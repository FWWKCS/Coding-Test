while True :
    N = int(input())
    if N == 0 : break

    total = 0
    for k in range(1,N+1) :
        total += k

    print(total)