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

w1 = sequence[:(N//2)]
w2 = sequence[(N//2):]

left = dfs([], w1, 0, 0)
right = dfs([], w2, 0, 0)

# hash
l_dict = {
    # 가능한 값: 횟수
}

r_dict = {
    # 가능한 값: 횟수
}

for l in left:
    if l not in l_dict: l_dict[l] = 1
    else: l_dict[l] += 1

for r in right:
    if r not in r_dict: r_dict[r] = 1
    else: r_dict[r] += 1


count = 0 # left에서 0을 선택하면, right에서 0을 찾는 경우 1가지를 미리 제외
if S == 0: count -= 1

for l in l_dict.keys(): 
    if S-l in r_dict: count += l_dict[l] * r_dict[S-l]

print(count)