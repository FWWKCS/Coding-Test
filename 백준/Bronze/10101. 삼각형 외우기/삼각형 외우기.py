angle = []

for _ in range(3) :
    angle.append(int(input()))

if sum(angle) != 180 : print('Error')
else :
    if angle.count(60) == 3 : print('Equilateral')
    elif len(list(set(angle))) == 2 : print('Isosceles')
    else : print('Scalene')