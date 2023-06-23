input = input().split()

h = int(input[0])
m = int(input[1])

if m-45 < 0 : 
    m = m + 15
    if h == 0 : h = 23
    else : h -= 1
else : m = m-45
    
print(h, m)