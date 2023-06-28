import sys
input = sys.stdin.readline

logCount = int(input())

state = {
    # dict 
    # # 내부적으로 해시 테이블로 구현
    # 검색 시간 복잡도는 O(1), 최악의 경우 O(n)
}

for _ in range(logCount) :
    data = input().split()
    state[data[0]] = data[1]

employee = sorted(state, reverse=True)

for e in employee :
    if state[e] != 'leave' : print(e)