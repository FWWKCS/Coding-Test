import sys
input = sys.stdin.readline

M = int(input())
S = set()

for _ in range(M) :
    order = input().rstrip()

    if order[:3] == 'add' :
        S.add(int(order[4:]))
    elif order[:6] == 'remove' :
        try :
            S.remove(int(order[7:]))
        except : pass
    elif order[:5] == 'check' :
        if int(order[6:]) in S : print(1)
        else : print(0)
    elif order[:6] == 'toggle' :
        if int(order[6:]) in S : 
            S.remove(int(order[7:]))
        else : 
            S.add(int(order[7:]))
    elif order[:3] == 'all' :
        S = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}
    elif order[:5] == 'empty' :
        S = set()