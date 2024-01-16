import sys
input = sys.stdin.readline

N = int(input())
sol = sorted(list(map(int, input().split())))

s = 0
e = len(sol)-1


min_s = None
max_s = None
comb = 2*int(10e9)


while s < e:
    total = sol[s]+sol[e]
    if abs(total) < comb:
        min_s = sol[s]
        max_s = sol[e]
        comb = abs(total)

    if total < 0: # 음수 부분을 감소
        s += 1
    elif total > 0: # 양수 부분을 감소
        e -= 1
    else: # 0이 되는 경우
        print(sol[s], sol[e])
        exit()

print(min_s, max_s)