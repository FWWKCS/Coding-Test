import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

def takeEarthworm(c, r) :
    global M, N, earthworm, field

    if c < 0 or c >= M or r < 0 or r >= N or field[r][c] != 1:
        return

    field[r][c] = 0

    takeEarthworm(c, r-1)  # 위로 1칸 이동 (상)
    takeEarthworm(c, r+1)  # 아래로 1칸 이동 (하)
    takeEarthworm(c-1, r)  # 왼쪽으로 1칸 이동 (좌)
    takeEarthworm(c+1, r)  # 오른쪽으로 1칸 이동 (우)


testCase = int(input())

for _ in range(testCase) :
    M, N, K = map(int, input().split()) # 가로, 세로, 배추 위치 수 
    
    field = [[0 for _ in range(M)] for _ in range(N)]
    earthworm = 0 # 지렁이

    for _ in range(K) :
        X, Y = map(int, input().split())
        field[Y][X] = 1

    # DFS 
    for r in range(N) :
        for c in range(M) :
            if field[r][c] == 1 :
                # 처음으로 직면한 영역에서 재귀함수를 통해 이어진 배추를 모두 탐색후 돌아오므로
                # 서로 붙어있는 영역 만큼 지렁이를 필요로 하면 된다
                takeEarthworm(c, r)
                earthworm += 1

    print(earthworm)