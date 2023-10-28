import sys
input = sys.stdin.readline

bestSeller = {
    # 책 이름 : 횟수
}

N = int(input())
for _ in range(N) :
    book = input().rstrip()
    if book not in bestSeller :
        bestSeller[book] = 1
    else :
        bestSeller[book] += 1

rank = sorted(bestSeller.items(), key = lambda x : (-x[1], x[0]))
print(rank[0][0])