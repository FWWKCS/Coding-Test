dataSet = int(input())

for _ in range(dataSet) :
    X, Y = map(int, input().split())

    if X < Y : print('NO BRAINS')
    else : print('MMM BRAINS')