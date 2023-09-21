# 참조 : https://puleugo.tistory.com/43

import sys
input = sys.stdin.readline

def round_off(x) :
    if x > 0 :
        return int(x + 0.5)
    elif x < 0 :
        return int(x - 0.5)
    else :
        return 0

n = int(input())
vote = sorted(list(int(input()) for _ in range(n)))

front = round_off(n*0.15)
back = n - front

vote = vote[front:back]

try :
    avg = round_off(sum(vote)/len(vote))
except :
    avg = 0

print(avg)