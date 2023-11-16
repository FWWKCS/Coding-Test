import sys
input = sys.stdin.readline

def check(L): # 최소 L의 거리만큼 C개의 공유기를 모두 놓을 수 있는지 확인
    count = 1 # start 위치에 공유기 하나 설치
    index = 0
    for i in range(1, N):
        if pos[i] - pos[index] >= L:
            count += 1
            index = i
    
    return count

N, C = map(int, input().split())
pos = sorted([int(input()) for _ in range(N)])

# 서로 인접한 공유기끼리는 모두 L이상의 거리를 가져야한다

L = -1 # 이분탐색을 진행한 인접 공유기의 최대 거리
start = 1 # 최소 거리
end = pos[-1] - pos[0]
while start <= end:
    mid_L = (start+end) // 2
    count = check(mid_L)
    if count >= C: 
        L = max(L, mid_L)
        start = mid_L + 1
    else: end = mid_L - 1

print(L)