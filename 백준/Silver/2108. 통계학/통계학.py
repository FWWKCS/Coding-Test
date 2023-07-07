testCase = int(input())

data = []

for _ in range(testCase) :
    data.append(int(input()))

data = sorted(data)

# 산술평균
print(round(sum(data)/testCase))

# 중앙값
print(data[testCase//2])

# 최빈값
current = data[0]
pre = None
freq = 1
mode = [] # (수, 빈도)

for k in range(1, len(data)) : 
    pre = current
    current = data[k]

    if current != pre : 
        mode.append((pre, freq))
        freq = 1
    else : freq += 1

pre = current
mode.append((pre, freq))

mode = sorted(mode, key = lambda x : (x[1], -x[0]), reverse = True)
# mode의 1번째 인덱스를 기준으로 정렬하고 동일한 값끼리 0번째 인덱스를 음수화 값에 대하여 오름차순 정렬

# 빈도가 가장 높은 데이터만 추출
maxFreq = mode[0][1]
mode = list(filter(lambda x : x[1] == maxFreq, mode))

# 두 번째로 작은 값
if len(mode) > 1 : 
    print(mode[1][0])
else : print(mode[0][0])

# 범위
print(data[-1]-data[0])