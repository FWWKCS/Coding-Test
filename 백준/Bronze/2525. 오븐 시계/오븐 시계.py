inputTime = input().split()

h = int(inputTime[0])
m = int(inputTime[1])

add = int(input())

if m + add >= 60 :
    h += ((m+add) // 60)
    if h > 23 : h = h % 24
    m = (m+add) % 60
elif m + add < 60 : m += add
    
print(h, m)