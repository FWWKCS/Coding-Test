import sys
input = sys.stdin.readline

# 에라토스테네스의 체
size = 1000000
numList = [i for i in range(size+1)]
numList[0], numList[1] = 0,0
for k in range(2, size+1) :
    if numList[k] == 0 : continue
    i = k
    while i*k <= size :
        numList[i*k] = 0
        i += 1

numList = set(numList)

count = int(input())
data = []

for _ in range(count) : 
    data.append(int(input()))

# 골드바흐의 추측: 2보다 큰 짝수는 두 소수의 합으로 나타낼 수 있다

# 어떤 수 a 아래의 소수를 구하고, 그 차가 소수이면 골드바흐 파티션
partition = []

for d in data :
    for x in range(2, d//2+1) :
        if x in numList and d-x in numList : 
            partition.append((x,d-x))
    
    print(len(partition))
    partition = []