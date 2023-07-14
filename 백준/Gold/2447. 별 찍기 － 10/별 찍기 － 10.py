def fractal(start_x, end_x, start_y, end_y) : # start_x, end_x, start_y, end_y
    global target
    if end_x <= start_x or end_y <= start_y : return

    # 가운데 영역을 비우기
    # 중간 영역의 길이 계산
    l = (end_x - start_x + 1) // 3

    # 제거 시점과 종점 계산, 인덱스로 연산
    dx_start = start_x + l
    dx_end = end_x - l

    dy_start = start_y + l
    dy_end = end_y - l

    for x in range(dx_start, dx_end+1) :
        for y in range(dy_start, dy_end+1) :
            if target[y][x] != ' ' :
                target[y][x] = ' '

     # 영역을 등분하여 각 영역에 재귀 호출
    for x in range(start_x, end_x + 1, l):
        for y in range(start_y, end_y + 1, l):
            fractal(x, x + l - 1, y, y + l - 1)
    
size = int(input())

target = [['*' for _ in range(size)] for _ in range(size)]

fractal(0, size-1, 0, size-1) # 인덱스로 전달
for t in target : 
    t = ''.join(t)
    print(t)