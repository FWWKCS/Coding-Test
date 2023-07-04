price, N, money = map(int, input().split())

print(max(0, price*N-money))