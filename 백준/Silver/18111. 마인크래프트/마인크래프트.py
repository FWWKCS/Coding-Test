import sys
input = sys.stdin.readline

def find_minTime(R, C, B) :
    global min_time, select_height
    for k in range(257) :
        # 영역을 k 높이로 고를때
        less = 0 # 모자란 블럭의 개수
        allocated_block = B # 기본 블럭의 개수부터 시작
        total_time = 0 # 최종 작업 시간

        for r in range(R) :
            for c in range(C) :
                # case 1. k 미만의 높이라면
                if field[r][c] < k :
                    # k까지 채우는데 필요한 블럭의 개수를 저장
                    less += k - field[r][c]

                # case 2. k 초과의 높이라면
                elif field[r][c] > k :
                    # k까지 깎아내고 깎아낸 블럭을 저장
                    allocated_block += field[r][c] - k
                    total_time += 2 * (field[r][c] - k)

        # 모자란 부분을 블럭으로 채울 수 있으면
        if less <= allocated_block :
            total_time += less

            # 최종 값 저장
            # 최소 시간이 같을때, 높은 층으로 땅을 고른다
            if total_time <= min_time :
                min_time = total_time
                select_height = k
        else : # 블럭 한도 초과 시 그 이상으로 땅을 고를 수 없음
            return 



N, M, B = map(int, input().split())
# 행, 열, 소지블럭

field = [list(map(int, input().split())) for _ in range(N)]

min_time = sys.maxsize # 연산된 최소시간
select_height = 0 # 최소시간을 가지는 높이

find_minTime(N, M, B)

print(min_time, select_height)