N = int(input())
sol = sorted(list(map(int, input().split())))

value = [0, 0, 0]
total = 4*int(10e9)

# 1개 고정 + 2포인터
for x in range(N-2):
    s = x + 1
    e = N-1

    while s < e:
        comb = sol[x] + sol[s] + sol[e]
        if abs(comb) < total:
            value = [sol[x], sol[s], sol[e]]
            total = abs(comb)

        if comb < 0:
            s += 1
        elif comb > 0:
            e -= 1
        else:
            print(sol[x], sol[s], sol[e])
            exit()

print(*value)