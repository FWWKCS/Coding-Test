testCase = int(input())

for _ in range(testCase) : 
    num = int(input())

    print(f'Pairs for {num}:', end = ' ')

    pair = []
    for i in range(1,12) :
        for j in range(i+1, 13) :
            if i+j == num :
                pair.append((i,j))

    for p in pair :
        if p == pair[-1] :
            print(f'{p[0]} {p[1]}')
        else :
            print(f'{p[0]} {p[1]}', end = ', ')

    if len(pair) == 0 : print()