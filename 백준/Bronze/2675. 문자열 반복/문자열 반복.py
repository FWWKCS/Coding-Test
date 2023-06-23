count = int(input())
makeSen = []

for i in range(count):
    info = input().split()
    rep = int(info[0])
    sen = info[1]

    tmp = []
    for j in range(len(sen)):
        tmp.append(sen[j]*rep)
        
    makeSen.append(''.join(tmp))

for i in makeSen : print(i)