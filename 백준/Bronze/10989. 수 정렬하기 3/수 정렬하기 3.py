import sys
input = sys.stdin.readline

# 양의 정수(or 자연수)로만 이루어져있는 경우
# 계수 정렬 
# 참조 : https://bowbowbow.tistory.com/8

# 메모리 제한 8MB 이므로 한 번에 모든 데이터를 처리하려고하면 메모리 초과 발생
# 정수 하나는 4byte, 문자 하나는 1byte

# 입력값은 10,000보다 작거나 같은 자연수이므로 카운팅 배열은 1부터 10000까지 (ary[0:9999])
# 입력을 받음과 동시에 카운팅 배열값 increment

countingAry = [0 for _ in range(10000)]

size = int(input())

for _ in range(size):
    val = int(input())
    countingAry[val-1] += 1

for v in range(10000) :
    if countingAry[v] == 0 : continue
    for _ in range(countingAry[v]) :
        print(v+1)
