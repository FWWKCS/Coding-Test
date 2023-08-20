import sys
input = sys.stdin.readline

while True :
    try :
        N = int(input())
    except :
        break

    k = ''
    while True :
        k += '1'

        if int(k) % N == 0 :
            break
    
    print(len(k))