import sys
input = sys.stdin.readline

def backtracking(depth, get, count):
    global num
    if depth == M: 
        print(*get)
        return

    for k in num:
        if count[k] != 0:
            get.append(k)
            count[k] -= 1
            backtracking(depth+1, get, count)
            get.pop()
            count[k] += 1

N, M = map(int, input().split())
num = sorted(list(map(int, input().split())))
count = {
    # 숫자: 개수
}
for x in num:
    if x not in count:
        count[x] = 1
    else: count[x] += 1

num = sorted(list(set(num)))

backtracking(0, [], count)