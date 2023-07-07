import sys
input = sys.stdin.readline

testCase = int(input())

data = []
mode = {
    # 데이터 값 : 빈도
}

for _ in range(testCase) :
    val = int(input())
    data.append(val)
    if val in mode : mode[val] += 1
    else : mode[val] = 1 

data = sorted(data)

# 산술평균
print(round(sum(data)/testCase))

# 중앙값
print(data[testCase//2])

# 최빈값
mxFrArr = [k for k,v in mode.items() if max(mode.values()) == v]

mxFrArr = sorted(mxFrArr)

if len(mxFrArr) > 1 : # 데이터 개수 구분
    # 두 번째 작은 값
    print(mxFrArr[1])
else : print(mxFrArr[0])

# 범위
print(data[-1]-data[0])