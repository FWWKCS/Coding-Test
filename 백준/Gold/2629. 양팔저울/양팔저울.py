N = int(input())
pendulum = list(map(int, input().split()))
count = int(input())
marble = list(map(int, input().split()))

possibility = [[False for _ in range(40001)] for _ in range(N)]
# possibility[r][c]: r번째 추까지 사용할 때 측정 가능한 무게가 c

for r in range(N):
    for c in range(len(possibility[r])):
        # 무게가 0인 경우는 항상 판별 가능하다 (모두 사용하지않으면 됨)
        if c == 0: 
            possibility[r][c] = True
            continue

        # r번째 추 무게와 같은 c는 판별가능하다 (r번 추 하나를 사용)
        if pendulum[r] == c : possibility[r][c] = True

        # r-1번 추까지 사용한 기록중 r번 추에서 찾을 무게 c를 뺀 곳의 무게는 판별 가능하다
        if r > 0 and possibility[r-1][abs(pendulum[r]-c)]:
            possibility[r][c] = True

        # r-1번 추까지 사용한 기록중 r번 추에서 찾을 무게 c와 더한 무게는 판별 가능하다
        if r > 0 and pendulum[r]+c < 40001 and possibility[r-1][pendulum[r]+c]:
            possibility[r][c] = True
        
        # r-1번 추까지 사용한 기록이 판별 가능하면 r번 추까지의 경우에도 판별 가능하다 
        # (r번 추를 사용하지 않으면 된다)
        if r > 0 and possibility[r-1][c]:
            possibility[r][c] = True

# for p in possibility: print(p)


for m in marble:
    if possibility[-1][m]: print('Y', end = ' ')
    else: print('N', end = ' ')