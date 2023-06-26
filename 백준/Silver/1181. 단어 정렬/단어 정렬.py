count = int(input())

data = []

for _ in range(count) :
    data.append(input())

# 중복제거
data = list(set(data))

# 사전 순 정렬
data.sort()
# lambda를 이용하여 길이순 정렬
data.sort(key = lambda x : len(x))

for d in data: print(d)