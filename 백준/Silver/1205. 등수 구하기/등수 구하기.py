import sys
input = sys.stdin.readline

N, newScore, P = map(int, input().split())
if N > 0 :
    ranking = list(map(int, input().split()))
else :
    ranking = []

rank = -1
ranked = True # 랭킹 여부

# 랭킹 등록 불가조건
if len(ranking) == P and newScore <= ranking[-1] : 
    ranked = False

if ranked :
    ranking.append(newScore)
    ranking.sort(reverse = True)

    ranking = ranking[:P]

    rank = ranking.index(newScore) + 1

print(rank)
