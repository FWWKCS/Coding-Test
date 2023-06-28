import sys
input = sys.stdin.readline

count = int(input())

Cards = list(map(int,input().split()))

cardDict = {
    # 카드번호 : 개수
}

for c in Cards :
    if c not in cardDict : 
        cardDict[c] = 1
    else :
        cardDict[c] += 1

test = int(input())

findValue = list(map(int,input().split()))

for v in findValue :
    if v not in cardDict : print(0, end = ' ')
    else : print(cardDict[v], end = ' ')