S = int(input())

x = 1
N = 0

while x <= S : 
    S -= x
    N += 1
    x += 1

print(N)