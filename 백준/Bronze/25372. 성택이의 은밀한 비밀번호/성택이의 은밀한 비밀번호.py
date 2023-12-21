N = int(input())
for _ in range(N):
    pwd = input()
    if 6 <= len(pwd) and len(pwd) <= 9: print('yes')
    else: print('no')