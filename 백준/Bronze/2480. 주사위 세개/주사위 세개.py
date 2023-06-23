inputDice = input().split()

a = int(inputDice[0])
b = int(inputDice[1])
c = int(inputDice[2])

price = 0

if (a == b and b == c) :
    price = 10000 + (a * 1000)
elif (a == b or a == c) : price = 1000 + (a * 100)
elif (b == c) : price = 1000 + (b * 100)
else :
    if (a > b and a > c) : price = a * 100
    elif (b > a and b > c) : price = b * 100
    elif (c > a and c > b) : price = c *100

print(price)
