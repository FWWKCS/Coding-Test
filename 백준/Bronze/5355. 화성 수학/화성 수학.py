testCase = int(input())

for _ in range(testCase) :
    data = list(input().split())
    x = float(data[0])
    for s in data[1:] :
        if s == '@' : x *= 3
        elif s == '%' : x += 5
        elif s == '#' : x -= 7

    print('%.2f' % x)