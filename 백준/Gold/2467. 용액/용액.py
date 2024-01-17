N = int(input())
sol = sorted(list(map(int, input().split())))

s = 0
e = N-1

value = [0, 0]
total = 2*int(10e9)

while s < e:
    comb = sol[s] + sol[e]
    if abs(comb) < total:
        total = abs(comb)
        value = [sol[s], sol[e]]

    if comb < 0:
        s += 1
    elif comb > 0:
        e -= 1
    else:
        print(sol[s], sol[e])
        exit()

print(*value)