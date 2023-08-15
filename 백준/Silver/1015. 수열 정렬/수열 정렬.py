import copy

N = int(input())
A = list(map(int, input().split()))

B = copy.deepcopy(A)

B.sort()

dict = {
    # A의 원소 : 최초 인덱스 (방문 횟수에 따라 점차 증가)
}

P = []

for a in A :
    if a not in dict :
        dict[a] = B.index(a)
    else :
        dict[a] += 1
    P.append(dict[a])

for p in P :
    print(p, end = ' ')