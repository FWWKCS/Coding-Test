N = int(input())

count = -1
x = N // 5

while x > -1 :
    y = (N - (5 * x)) // 3

    if 5*x + 3*y == N :
        count = x+y
        break

    else :
        x -= 1

print(count)