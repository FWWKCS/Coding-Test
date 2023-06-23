data = []

while True :
    inputValue = input().split()
    if inputValue[0] == '0' and inputValue[1] == '0' and inputValue[2] == '0' : break
    data.append([int(inputValue[0]),int(inputValue[1]),int(inputValue[2])])

for db in data :
    if len(list(set(db))) == 1 : print('Equilateral')
    else :
        db.sort()
        if db[2] >= db[0] + db[1] : print('Invalid')
        elif len(list(set(db))) == 2 : print('Isosceles')
        else : print('Scalene') 