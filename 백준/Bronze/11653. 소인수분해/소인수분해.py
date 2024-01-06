data = int(input())
opr = 2

while data != 1 :
    if data % opr == 0 : 
        print(opr)
        data /= opr
    else : opr += 1