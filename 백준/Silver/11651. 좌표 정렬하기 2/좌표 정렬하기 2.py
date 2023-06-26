count = int(input())

data = []
tmp = []

for _ in range(count) :
    data.append(tuple(map(int,input().split())))

# lambda를 이용하여 
# data의 1번째 인덱스를 오름차순 정렬 
# 동일한 값인 경우 0번째 인덱스를 오름차순 정렬
data.sort(key = lambda x : (x[1], x[0]))

for p in data :
    print(f"{p[0]} {p[1]}")