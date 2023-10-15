while True:
    try:
        N, S = map(int, input().split())
    except : break

    print(S // (N+1))