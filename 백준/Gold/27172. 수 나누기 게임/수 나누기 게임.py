import sys
input = sys.stdin.readline

N = int(input())
num = list(map(int, input().split()))
score = [0 for _ in range(1000001)] # 점수 출력 리스트
exist = [False for _ in range(1000001)] # num에 있는 수
for n in num: exist[n] = True

for n in num:
    my_score = 0
    for x in range(2*n, 1000001, n):
        score[x] -= 1
        if exist[x]: my_score += 1
    
    score[n] += my_score

for n in num:
    print(score[n], end = ' ')