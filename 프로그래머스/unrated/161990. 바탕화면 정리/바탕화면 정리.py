def solution(wallpaper):
    table = [list(wallpaper[i]) for i in range(len(wallpaper))]

    # 좌측 상단 지점 탐색
    lux, luy = 999, 999
    # 최초로 발견한 #이 있는 위치 
    for t in range(len(table)) :
        if '#' in table[t] : 
            luy = min(t, luy)
            lux = min(table[t].index('#'), lux)

    # 우측 하단 지점 탐색
    rdx, rdy = 0, 0
    # 역순으로 최초 발견한 #이 있는 위치
    for t in range(len(table)-1, -1, -1) :
        if '#' in table[t] :
            rdy = max(t, rdy)

            for c in range(len(table[t])-1, -1, -1) :
                if table[t][c] == '#' :
                    rdx = max(c, rdx)

    return [luy, lux, rdy+1, rdx+1]