import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T) :
    is_square = True
    pos = [] # 좌표값 리스트
    for _ in range(4) :
        pos.append(tuple(map(int, input().split())))
    
    pos = sorted(pos, key = lambda x : (x[0], -x[1]))

    # 인접한 두 점의 거리가 같고, 두 대각선의 길이가 같으면 정사각형
    # 거리
    length_1 = ((pos[0][0]-pos[1][0])**2) + ((pos[0][1]-pos[1][1])**2)
    length_2 = ((pos[0][0]-pos[2][0])**2) + ((pos[0][1]-pos[2][1])**2)
    # 대각선
    diagonal_1 = ((pos[0][0]-pos[3][0])**2) + ((pos[0][1]-pos[3][1])**2)
    diagonal_2 = ((pos[1][0]-pos[2][0])**2) + ((pos[1][1]-pos[2][1])**2)
    
    if length_1 != length_2 : is_square = False
    if diagonal_1 != diagonal_2 : is_square = False
    
    if is_square : print(1)
    else : print(0)