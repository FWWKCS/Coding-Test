N, C = map(int, input().split())
w = list(map(int, input().split()))

def dfs(sector, weight, depth, current):
    if depth >= len(weight):
        sector.append(current)
        return sector
    
    # not selecet
    sector = dfs(sector, weight, depth+1, current)

    # select
    sector = dfs(sector, weight, depth+1, current+weight[depth])

    return sector

def binary_search(array, find_value):
    s = 0
    e = len(array)-1
    pivot = -1

    while s <= e:
        pivot = (s+e) // 2

        if array[pivot] <= find_value:
            s = pivot + 1
        else:
            e = pivot - 1
    
    pivot = (s+e) // 2
    return pivot + 1


sector1 = []
sector2 = []

# Meet in middle
w1 = w[:(N//2)]
w2 = w[(N//2):]

sector1 = dfs(sector1, w1, 0, 0)
sector2 = sorted(dfs(sector2, w2, 0, 0))

total = 0
# binary search
for x in sector1:
    if C-x < 0: continue

    total += binary_search(sector2, C-x)

print(total)