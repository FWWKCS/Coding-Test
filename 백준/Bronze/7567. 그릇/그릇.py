plate = input()

length = 10
current = plate[0]

for p in plate[1:] :
    if p == current : 
        length += 5
    else :
        length += 10
        current = p

print(length)