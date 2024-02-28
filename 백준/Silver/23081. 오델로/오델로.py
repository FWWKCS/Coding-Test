import sys
input = sys.stdin.readline

ax, ay = -1, -1
answer = 0

N = int(input())
table = [list(input().rstrip()) for _ in range(N)]
target = []

for r in range(N):
    for c in range(N):
        if table[r][c] == '.': target.append((r, c))

for r, c in target:
    total = 0
    # L 방향
    count = 0
    reverse = False
    x = c - 1
    while x > -1 and table[r][x] != '.':
        if table[r][x] == 'B': 
            reverse = True
            break
        count += 1
        x -= 1
    
    if reverse: total += count
    
    # R 방향
    x = c + 1
    count = 0
    reverse = False
    while x < N and table[r][x] != '.':
        if table[r][x] == 'B':
            reverse = True
            break
        count += 1
        x += 1
    
    if reverse: total += count

    # U 방향
    y = r - 1
    count = 0
    reverse = False
    while y > -1 and table[y][c] != '.':
        if table[y][c] == 'B':
            reverse = True
            break
        count += 1
        y -= 1

    if reverse: total += count

    # D 방향
    y = r + 1
    count = 0
    reverse = False
    while y < N and table[y][c] != '.':
        if table[y][c] == 'B':
            reverse = True
            break
        count += 1
        y += 1

    if reverse: total += count

    # L U 방향
    x = c - 1
    y = r - 1
    count = 0
    reverse = False
    while x > -1 and y > -1 and table[y][x] != '.':
        if table[y][x] == 'B':
            reverse = True
            break
        count += 1
        x -= 1
        y -= 1
    
    if reverse: total += count

    # R U 방향
    x = c + 1
    y = r - 1
    count = 0
    reverse = False
    while x < N and y > -1 and table[y][x] != '.':
        if table[y][x] == 'B':
            reverse = True
            break
        count += 1
        x += 1
        y -= 1
    
    if reverse: total += count

    # L D 방향
    x = c - 1
    y = r + 1
    count = 0
    reverse = False
    while x > -1 and y < N and table[y][x] != '.':
        if table[y][x] == 'B':
            reverse = True
            break
        count += 1
        x -= 1
        y += 1
    
    if reverse: total += count

    # R D 방향
    x = c + 1
    y = r + 1
    count = 0
    reverse = False
    while x < N and y < N and table[y][x] != '.':
        if table[y][x] == 'B':
            reverse = True
            break
        count += 1
        x += 1
        y += 1

    if reverse: total += count

    if answer < total:
        answer = total
        ax = c
        ay = r

if answer != 0:
    print(ax, ay)
    print(answer)
else: print('PASS')