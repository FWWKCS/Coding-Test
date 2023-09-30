import sys
input = sys.stdin.readline

def binary_search(start, end) :
    global M
    pivot_height = 0
    near_height = 0 # 정확히 M이 되지못할 때, 최종적으로 pivot_height대신 출력
    while start <= end :
        pivot_height = (start + end) // 2 

        # 중간 높이값에 따른 캘 수 있는 나무 연산
        total = 0
        for t in trees[::-1] :
            if t <= pivot_height : break
            total += t - pivot_height

        # 분기에 따라 중간값 변경
        if total == M : return pivot_height
        elif total > M : 
            near_height = pivot_height
            start = pivot_height + 1
        else : end = pivot_height - 1

    return near_height

N, M = map(int, input().split())
trees = sorted(list(map(int, input().split())))

height = binary_search(0, trees[-1])

print(height)