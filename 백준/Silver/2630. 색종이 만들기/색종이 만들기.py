def slice_paper(length, R, C) :
    global white, blue
    is_white = False
    is_blue = False
    # length ^ 2 의 칸 중 1과 0이 모두 있으면 분할
    for r in range(R, R+length) :
        for c in range(C, C+length) :
            if (is_white and paper[r][c] == 1) or (is_blue and paper[r][c] == 0) :
                # 1구역
                slice_paper(length//2, R, C)
                # 2구역
                slice_paper(length//2, R, C+(length//2))
                # 3구역
                slice_paper(length//2, R+(length//2), C)
                # 4구역
                slice_paper(length//2, R+(length//2), C+(length//2))
                return
            elif paper[r][c] == 0 : is_white = True
            elif paper[r][c] == 1 : is_blue = True


    # 그렇지 않으면 색을 판별하고 개수 추가 후 반복 종료
    if is_white : white += 1
    elif is_blue : blue += 1

N = int(input())

paper = [list(map(int, input().split())) for _ in range(N)]
white = 0
blue = 0

slice_paper(N, 0, 0)

print(white)
print(blue)