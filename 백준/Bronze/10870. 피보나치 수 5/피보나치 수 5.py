def fibo(x) :
    if x == 0 : return 0
    elif x == 1 : return 1

    return fibo(x-2) + fibo(x-1)

x = int(input())

print(fibo(x))
