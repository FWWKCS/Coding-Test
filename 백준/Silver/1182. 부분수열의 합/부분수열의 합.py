from collections import deque

N, S = map(int, input().split())
sequence = list(map(int, input().split()))

# MITM
def dfs(sector, array, depth, value):
    if depth == len(array):
        sector.append(value)
        return sector
    
    # not select
    sector = dfs(sector, array, depth+1, value)

    # select
    sector = dfs(sector, array, depth+1, value+array[depth])

    return sector

# binary_search
def binary_search(array, find_value):
    global count

    s = 0
    e = len(array)-1

    pivot = (s+e) // 2
    while s <= e:
        pivot = (s+e) // 2
        if array[pivot] <= find_value:
            s = pivot + 1
        elif array[pivot] > find_value:
            e = pivot - 1
    up = e # 탐색 값의 상한

    if array[e] != find_value: return

    s = 0
    e = len(array)-1

    pivot = (s+e) // 2
    while s <= e:
        pivot = (s+e) // 2
        if array[pivot] < find_value:
            s = pivot + 1
        elif array[pivot] >= find_value:
            e = pivot - 1
    down = s # 탐색 값의 하한

    count += up - down + 1

w1 = sequence[:(N//2)]
w2 = sequence[(N//2):]

left = dfs([], w1, 0, 0)
right = sorted(dfs([], w2, 0, 0))

count = 0 # left에서 0을 선택하면, right에서 0을 찾는 경우 1가지를 미리 제외
if S == 0: count -= 1

for i in range(len(left)): 
    binary_search(right, S-left[i])

print(count)