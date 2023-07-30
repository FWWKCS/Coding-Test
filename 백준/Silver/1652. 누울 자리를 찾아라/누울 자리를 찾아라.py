N = int(input())

table = []
w = 0 # 가로
l = 0 # 세로

for _ in range(N) :
    table.append(list(input()))

for k in range(N) :
    # 가로 개수
    length = 0
    x = 0
    while x != N :
        if table[k][x] == 'X' : 
            if length >= 2 : 
                w += 1
            
            x += 1
            length = 0
            continue

        length += 1
        x += 1

    if length >= 2 : w += 1

    # 세로 개수
    length = 0
    y = 0
    while y != N :
        if table[y][k] == 'X' :            
            if length >= 2 :
                l += 1
            
            y += 1
            length = 0
            continue

        length += 1
        y += 1

    if length >= 2 : l += 1

print(w,l)