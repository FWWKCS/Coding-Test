checkAry = []

while True :
    data = input().split()
    if int(data[0]) == 0 and int(data[1]) == 0 : break
    checkAry.append((int(data[0]),int(data[1])))

for c in checkAry :
    if c[1] % c[0] == 0 : print('factor')
    elif c[0] % c[1] == 0 : print('multiple')
    else : print('neither')