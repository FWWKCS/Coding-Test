while True:
    n = int(input())
    if n == 0: break

    n -= 1
    val = []
    s = str(bin(n))
    # print(s[2:])

    for exp in range(len(s)-1, 1, -1):
        # print(s[exp])
        if s[exp] != '0':
            val.append(pow(3, len(s)-1-exp))

    print('{', end='')
    for i in range(len(val)):
        print(' ', end='')
        print(val[i], end='')
        if i != len(val)-1:
            print(',', end='')
    
    print(' }')