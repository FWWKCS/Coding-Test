import sys
input = sys.stdin.readline

N, M, P = map(int, input().split())
success = True
for _ in range(N) :
    tower = sorted(list(map(int, input().split())))

    # -1을 발견하면 P는 2배
    items = 0 # 한 기지의 아이템의 개수
    for i in range(M) :
        if tower[i] == -1 : items += 1
        else : break

    # 최대한 나아가면서 자신보다 높은적이 나오는 순간 아이템 사용
    progress = items # -1 이상의 인덱스에서 시작
    while progress != M :
        if P >= tower[progress] :
            P += tower[progress]
            progress += 1
        elif items == 0 and P < tower[progress] :
            success = False
            break
        else :
            items -= 1
            P *= 2

    # 점령을 완료했으나 아직 아이템이 남았다면 모두 사용
    if items > 0 : P *= 2 ** items

    if not success : break

if success : print(1)
else : print(0)
