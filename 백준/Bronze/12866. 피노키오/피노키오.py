N = int(input())
line = input()

A = 0
G = 0
C = 0
T = 0
for i in line:
    if i == 'A': A += 1
    elif i == 'G': G += 1
    elif i == 'C': C += 1
    else: T += 1

MOD = 1000000007
print((A*G*C*T)%MOD)