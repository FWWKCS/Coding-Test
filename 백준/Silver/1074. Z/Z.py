def find_sector(L, r, c) :
    global count

    if L == 1 : return

    sector = -1
    row = r
    col = c

    # 구역 판별
    # 1구역
    if r < L//2 and c < L//2 : 
        sector = 1
        # r, c 재조정 없음
    # 2구역
    elif r < L//2 and c >= L//2 : 
        sector = 2
        col = c - L//2
    # 3구역
    elif r >= L//2 and c < L//2 : 
        sector = 3
        row = r - L//2
    # 4구역
    else : 
        sector = 4
        row = r - L//2
        col = c - L//2

    # 이전 구역 방문횟수 누적
    count += ((L//2) ** 2) * (sector - 1)

    # 재귀함수 호출
    find_sector(L//2, row, col)


N, R, C = map(int, input().split())

length = 2 ** N
count = 0

find_sector(length, R, C)

print(count)