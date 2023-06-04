# https://www.acmicpc.net/problem/10811

# 바구니는 1, 2, 3, ..., n 순으로 일렬 정렬
# 범위를 정해 그 구간의 바구니를 역순으로 재정렬

# input-----------
# overall range , count

# output----------

# 5 4
# 1 2 : 2 1 3 4 5
# 3 4 : 2 1 4 3 5
# 1 4 : 3 4 1 2 5
# 2 2 : 3 4 1 2 5 No Change

# 3 4 1 2 5

data = input().split()
overallRange = int(data[0])
basket = list(range(1,overallRange+1))
count = int(data[1])

for i in range(count):
    getRange = input().split()
    a = int(getRange[0])
    b = int(getRange[1])

    tmp = []
    tmp = basket[a-1:b]
    tmp.reverse()
    
    for k in range(b-a+1) : 
        basket.remove(basket[a-1])
    
    for k in range(len(tmp)):
        basket.insert(a-1+k, tmp[k])

for i in basket : print(i, end = ' ')