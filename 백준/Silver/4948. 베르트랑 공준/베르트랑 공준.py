import math

data = []

while True :
    i = int(input())
    if i == 0 : break
    else : data.append(i)

# 에라토스테네스의 체
maxVal = 123456 * 2 
numlist = [i for i in range(maxVal + 1)] # 0 ~ 123456

numlist[0], numlist[1] = 0, 0 # 0과 1은 소수가 아님

# 1234567 = ( 351.xxx ) ^ 2
for k in range(2,int(math.sqrt(maxVal))) : # 2부터 시작
    if numlist[k] == 0 : continue
    i = k
    while i*k <= maxVal :
        numlist[i*k] = 0
        i += 1

# 출력
for d in data :
    count = 0
    for n in numlist[d+1:2*d] :
        if n > 0 : count += 1

    if d == 1 : count += 1
    print(count)