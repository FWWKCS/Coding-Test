import sys
input = sys.stdin.readline

def split(start, end):
    global S
    if start == end: 
        S = max(S, histogram[start])
        return histogram[start]
    
    mid = (start+end)//2
    left_height = split(start, mid)
    right_height = split(mid+1, end)

    S = max(S, min(left_height, right_height)*(end-start+1))

    p = mid
    q = mid+1
    p_h = histogram[p]
    q_h = histogram[q]
    S = max(S, min(p_h, q_h)*(q-p+1))
    while p > start and q < end:
        if histogram[p-1] < histogram[q+1]:
            q += 1
            q_h = min(q_h, histogram[q])
            S = max(S, min(p_h, q_h)*(q-p+1))
        else:
            p -= 1
            p_h = min(p_h, histogram[p])
            S = max(S, min(p_h, q_h)*(q-p+1))

    # 왼쪽이 남았다면
    while p > start:
        p -= 1
        p_h = min(p_h, histogram[p])
        S = max(S, min(p_h, q_h)*(q-p+1))
    
    # 오른쪽이 남았다면
    while q < end:
        q += 1
        q_h = min(q_h, histogram[q])
        S = max(S, min(p_h, q_h)*(q-p+1))

    return min(p_h, q_h)

while True: 
    S = 0 # 넓이의 최댓값
    data = list(map(int, input().split()))
    if data[0] == 0 : break
    count = data[0]
    histogram = data[1:]

    split(0, count-1)
    print(S)