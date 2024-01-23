N = int(input())
total = 0
tri = 0
for i in range(1, N+1): 
    total += i
    tri += i**3
print(total)
print(total ** 2)
print(tri)
